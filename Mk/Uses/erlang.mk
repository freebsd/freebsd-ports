# $FreeBSD$
#
# Handle Erlang related ports
#
# Feature:	erlang
# Usage:	USES=erlang
# Valid ARGS:	rebar, rebar3, or no argument (custom build)
#
# Additional variables:
#
# ERL_APP_NAME		- Erlang app name as installed in Erlang's lib dir (minus version)
# ERL_APP_ROOT		- Root directory for this Erlang app
# REBAR_CMD		- Path to the "rebar" command
# REBAR3_CMD		- Path to the "rebar3" command
# REBAR_PROFILE		- Rebar profile
# REBAR_TARGETS		- Rebar target list (usually compile, maybe escriptize)
# ERL_BUILD_NAME	- Build name for rebar3
# ERL_BUILD_DEPS	- List of BUILD_DEPENDS in category/portname format
# ERL_RUN_DEPS		- List of RUN_DEPENDS in category/portname format
# ERL_DOCS		- List of documentation files and directories
#
# MAINTAINER: olgeni@FreeBSD.org

.if !defined(_INCLUDE_USES_ERLANG_MK)
_INCLUDE_USES_ERLANG_MK=yes

ERL_APP_NAME?=		${PORTNAME}
ERL_APP_ROOT?=		${PREFIX}/lib/erlang/lib/${ERL_APP_NAME}-${PORTVERSION}
REBAR_CMD=		${LOCALBASE}/bin/rebar
REBAR3_CMD=		${LOCALBASE}/bin/rebar3
REBAR_PROFILE?=		default
REBAR_TARGETS?=		compile
ERL_BUILD_NAME?=	default
ERL_BUILD_DEPS?=
ERL_RUN_DEPS?=
ERL_DOCS?=		README*

# VERSION is used in every Erlang pkg-plist
PLIST_SUB+=		VERSION="${PORTVERSION}"

BUILD_DEPENDS+=	erl:lang/erlang
RUN_DEPENDS+=	erl:lang/erlang

.if ${erlang_ARGS:Mrebar}
BUILD_DEPENDS+=	rebar>=0:devel/rebar
.endif

.if ${erlang_ARGS:Mrebar3}
BUILD_DEPENDS+=	rebar3>=0:devel/rebar3
.endif

.for depend in ${ERL_BUILD_DEPS}
BUILD_DEPENDS+=	${depend:T}>=0:${depend}
.endfor

.for depend in ${ERL_RUN_DEPS}
RUN_DEPENDS+=	${depend:T}>=0:${depend}
.endfor

.if ${erlang_ARGS:Mrebar}
ERLANG_COMPILE=	${REBAR_CMD}
.endif

.if ${erlang_ARGS:Mrebar3}
ERLANG_COMPILE=	HOME=${WRKDIR} ${REBAR3_CMD}
.endif

_USES_patch+=	650:post-patch-erlang
post-patch-erlang:
	@${FIND} ${WRKSRC} -name .gitignore -delete
# Attempt to remove all traces of {vsn, ....}; replace with actual PORTVERSION
	@if [ -f ${WRKSRC}/src/${ERL_APP_NAME}.app.src ]; then \
		${REINPLACE_CMD} -i '' -e 's/{ *vsn,.*}/{vsn, "${PORTVERSION}"}/' \
			${WRKSRC}/src/${ERL_APP_NAME}.app.src; \
	fi
	@if [ -f ${WRKSRC}/ebin/${ERL_APP_NAME}.app ]; then \
		${REINPLACE_CMD} -i '' -e 's/{ *vsn,.*}/{vsn, "${PORTVERSION}"}/' \
			${WRKSRC}/ebin/${ERL_APP_NAME}.app; \
	fi
	@${GREP} -l "%%LOCALBASE%%" $$(${FIND} ${WRKSRC}) \
		| ${XARGS} ${REINPLACE_CMD} -i '' -e "s@%%LOCALBASE%%@${LOCALBASE}@"
	@${GREP} -l "%%PORTVERSION%%" $$(${FIND} ${WRKSRC}) \
		| ${XARGS} ${REINPLACE_CMD} -i '' -e "s@%%PORTVERSION%%@${PORTVERSION}@"
# Always try to build with the system version of rebar and rebar3
	@if [ -f ${WRKSRC}/rebar.config ]; then \
		${REINPLACE_CMD} -i '' -e "s@\./rebar3@${REBAR3_CMD}@; s@\./rebar@${REBAR_CMD}@" \
			${WRKSRC}/rebar.config; \
	fi
	@${RM} -f ${WRKSRC}/src/*.orig ${WRKSRC}/include/*.orig

.if !target(do-build)
do-build:
# This will cause calls to local rebar and rebar3 to fail; makes it easier to spot them
	@${RM} -f ${WRKSRC}/rebar ${WRKSRC}/rebar3
.for target in ${REBAR_TARGETS}
# Remove rebar.lock every time - it can be created again after each run of rebar3
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && REBAR_PROFILE=${REBAR_PROFILE} ${ERLANG_COMPILE} ${target}
.endfor
.endif # !target(do-build)

.if !target(do-install)
do-install:
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/src
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} \* ${STAGEDIR}${ERL_APP_ROOT}/src
	@${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/ebin
.if ${erlang_ARGS:Mrebar3}
	${INSTALL_DATA} ${WRKSRC}/_build/${ERL_BUILD_NAME}/lib/${ERL_APP_NAME}/ebin/* \
		${STAGEDIR}${ERL_APP_ROOT}/ebin
.else
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${ERL_APP_ROOT}/ebin
.endif
	if [ -d ${WRKSRC}/include ]; then \
		${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/include; \
		cd ${WRKSRC}/include && ${COPYTREE_SHARE} \* ${STAGEDIR}${ERL_APP_ROOT}/include; \
	fi
	if [ -d ${WRKSRC}/priv ]; then \
		${MKDIR} ${STAGEDIR}${ERL_APP_ROOT}/priv; \
		cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${ERL_APP_ROOT}/priv; \
	fi
.if ${ERL_DOCS} != ""
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${ERL_DOCS}
	if [ -d "${WRKSRC}/${file}" ]; then \
		cd ${WRKSRC} && ${COPYTREE_SHARE} ${file} ${STAGEDIR}${DOCSDIR}; \
	else \
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}; \
	fi
.endfor
.endif # .if ${ERL_DOCS} != ""
.if ${REBAR_TARGETS:Mescriptize}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.endif
.endif # !target(do-install)

.endif #!defined(_INCLUDE_USES_ERLANG_MK)
