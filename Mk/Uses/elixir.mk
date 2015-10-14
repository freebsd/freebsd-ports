# $FreeBSD$
#
# Handle Elixir related ports
#
# Feature:	elixir
# Usage:	USES=elixir
# Valid ARGS:	does not require args
#
# Additional variables:
#
# ELIXIR_APP_NAME	- Elixir app name as installed in Elixir's lib directory
# ELIXIR_LIB_ROOT	- Elixir default library path
# ELIXIR_APP_ROOT	- Root directory for this Elixir app
# ELIXIR_HIDDEN		- Applications to be hidden from the code path; usually ${PORTNAME}
# ELIXIR_LOCALE		- An UTF-8 locale to be used by Elixir during builds (any UTF-8 locale is good)
# MIX_CMD		- The "mix" command
# MIX_COMPILE		- The "mix" command used to compile an Elixir app
# MIX_REWRITE		- Automatically replace Mix dependencies with code paths
# MIX_BUILD_DEPS	- List of BUILD_DEPENDS in category/portname format
#			(commonly referenced to as "deps" in Erlang and Elixir)
# MIX_RUN_DEPS		- List of RUN_DEPENDS in category/portname format
# MIX_DOC_DIRS		- Extra doc directories to be installed in DOCSDIR
# MIX_DOC_FILES		- Extra doc files to be installed in DOCSDIR (usually README.md)
# MIX_ENV		- Environment for the Mix build (same format as MAKE_ENV)
# MIX_ENV_NAME		- Name of the Mix build environment, usually "prod"
# MIX_BUILD_NAME	- Name of the build output in _build/, usually ${MIX_ENV_NAME}
# MIX_TARGET		- Name of the Mix target, usually "compile"
# MIX_EXTRA_APPS	- List of sub-applications to be built, if any
# MIX_EXTRA_DIRS	- List of extra directories to be installed in ELIXIR_APP_ROOT
# MIX_EXTRA_FILES	- List of extra files to be installed in ELIXIR_APP_ROOT
#
# MAINTAINER: olgeni@FreeBSD.org

.if !defined(_INCLUDE_USES_ELIXIR_MK)
_INCLUDE_USES_ELIXIR_MK=yes

.if !empty(elixir_ARGS)
IGNORE=	USES=elixir does not require args
.endif

ELIXIR_APP_NAME?=	${PORTNAME}
ELIXIR_LIB_ROOT?=	${LOCALBASE}/lib/elixir/lib
ELIXIR_APP_ROOT?=	${PREFIX}/lib/elixir/lib/${ELIXIR_APP_NAME}
ELIXIR_HIDDEN?=		"^${ELIXIR_APP_NAME}$$"
ELIXIR_LOCALE?=		en_US.UTF-8
MIX_CMD?=		${LOCALBASE}/bin/mix
MIX_COMPILE?=		${SETENV} ${MIX_ENV} LANG=${ELIXIR_LOCALE} MIX_ENV=${MIX_ENV_NAME} ELIXIR_HIDDEN=${ELIXIR_HIDDEN} ${MIX_CMD} ${MIX_TARGET}
MIX_REWRITE?=
MIX_BUILD_DEPS?=
MIX_RUN_DEPS?=
MIX_DOC_DIRS?=
MIX_DOC_FILES?=		README.md
MIX_ENV?=
MIX_ENV_NAME?=		prod
MIX_BUILD_NAME?=	prod
MIX_TARGET?=		compile
MIX_EXTRA_APPS?=
MIX_EXTRA_DIRS?=
MIX_EXTRA_FILES?=

BUILD_DEPENDS+=	elixir:lang/elixir
RUN_DEPENDS+=	elixir:lang/elixir

.for depend in ${MIX_BUILD_DEPS}
BUILD_DEPENDS+=	${depend:T}>=0:${depend}
.endfor

.for depend in ${MIX_RUN_DEPS}
RUN_DEPENDS+=	${depend:T}>=0:${PORTSDIR}/${depend}
.endfor

.if !target(do-build)
do-build:
.if ${MIX_REWRITE} != ""
	@${REINPLACE_CMD} -i '' -E -e "s@{.*(only|optional): .*},?@@; s@{ *:([a-zA-Z0-9_]+), *(github:|\").*}@{ :\1, path: \"${ELIXIR_LIB_ROOT}/\\1\", compile: false }@" ${WRKSRC}/mix.exs
.endif
	@${RM} -f ${WRKSRC}/mix.lock
	@cd ${WRKSRC} && ${MIX_COMPILE}
.for app in ${MIX_EXTRA_APPS}
	@${RM} -f ${WRKSRC}/${app}/mix.lock
	@cd ${WRKSRC}/${app} && ${MIX_COMPILE}
.endfor
.endif # .if !target(do-build)

.if !target(do-install)
do-install:
	@${MKDIR} ${STAGEDIR}${ELIXIR_APP_ROOT}
	@${MKDIR} ${STAGEDIR}${ELIXIR_APP_ROOT}/lib
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${ELIXIR_APP_ROOT}/lib
	@${MKDIR} ${STAGEDIR}${ELIXIR_APP_ROOT}/ebin
	${INSTALL_DATA} ${WRKSRC}/_build/${MIX_BUILD_NAME}/lib/${ELIXIR_APP_NAME}/ebin/* \
		${STAGEDIR}${ELIXIR_APP_ROOT}/ebin
	if [ -d ${WRKSRC}/priv ]; then \
		${MKDIR} ${STAGEDIR}${ELIXIR_APP_ROOT}/priv; \
		cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${ELIXIR_APP_ROOT}/priv; \
	fi
.if ${MIX_DOC_FILES} != "" || ${MIX_DOC_DIRS} != ""
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.endif
.for file in ${MIX_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.for dir in ${MIX_DOC_DIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DOCSDIR}
.endfor
.for file in ${MIX_EXTRA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${ELIXIR_APP_ROOT}
.endfor
.for dir in ${MIX_EXTRA_DIRS}
	@${MKDIR} ${STAGEDIR}${ELIXIR_APP_ROOT}/${dir}
	cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}${ELIXIR_APP_ROOT}/${dir}
.endfor
.for app in ${MIX_EXTRA_APPS}
	${INSTALL_DATA} ${WRKSRC}/${app}/_build/${MIX_BUILD_NAME}/lib/*/ebin/* \
		${STAGEDIR}${ELIXIR_APP_ROOT}/ebin
.endfor
.endif # .if !target(do-install)

.endif #!defined(_INCLUDE_USES_ELIXIR_MK)
