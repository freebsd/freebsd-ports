PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	26.2.5.15
PORTEPOCH=	1
CATEGORIES=	lang parallel
PKGNAMESUFFIX=	-wx
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang bindings for wxWindows
WWW=		https://www.erlang.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=25.0:lang/erlang
RUN_DEPENDS=	erlang>=25.0:lang/erlang

USES=		autoreconf:build gl gmake perl5 xorg
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_GL=		gl glu
USE_PERL5=	build
USE_WX=		3.2+

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads \
			--with-wx-config=${WX_CONFIG} \
			--without-javac \
			--without-odbc
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	DEBUGGER_VERSION=${DEBUGGER_VERSION} \
		ET_VERSION=${ET_VERSION} \
		OBSERVER_VERSION=${OBSERVER_VERSION} \
		WX_VERSION=${WX_VERSION}

DEBUGGER_VERSION=	5.3.4
ET_VERSION=		1.7
OBSERVER_VERSION=	2.15.1
WX_VERSION=		2.4.1
WX_APPS=		wx debugger et observer

pre-configure:
	@if [ ! $$(${CAT} ${WRKSRC}/lib/debugger/vsn.mk | ${GREP} -E "DEBUGGER_VSN *=" | ${CUT} -w -f3) = ${DEBUGGER_VERSION} ]; then \
		${ECHO_MSG} "===>  DEBUGGER_VERSION (${DEBUGGER_VERSION}) in Makefile does not match value in lib/debugger/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/et/vsn.mk | ${GREP} -E "ET_VSN *=" | ${CUT} -w -f3) = ${ET_VERSION} ]; then \
		${ECHO_MSG} "===>  ET_VERSION (${ET_VERSION}) in Makefile does not match value in lib/et/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/observer/vsn.mk | ${GREP} -E "OBSERVER_VSN *=" | ${CUT} -w -f3) = ${OBSERVER_VERSION} ]; then \
		${ECHO_MSG} "===>  OBSERVER_VERSION (${OBSERVER_VERSION}) in Makefile does not match value in lib/observer/vsn.mk"; exit 1; \
	fi
	@if [ ! $$(${CAT} ${WRKSRC}/lib/wx/vsn.mk | ${GREP} -E "WX_VSN *=" | ${CUT} -w -f3) = ${WX_VERSION} ]; then \
		${ECHO_MSG} "===>  WX_VERSION (${WX_VERSION}) in Makefile does not match value in lib/wx/vsn.mk"; exit 1; \
	fi

do-build:
.for app in wx debugger et observer
	cd ${WRKSRC}/lib/${app} && ${SETENV} ERL_LIBS=${WRKSRC}/lib ${GMAKE} ERL_TOP=${WRKSRC} TARGET=${CONFIGURE_TARGET}
.endfor
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/erl_gl.so
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/wxe_driver.so
	${MV} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/*.so ${WRKSRC}/lib/wx/priv
	${RMDIR} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}

do-install:
.for app in ${WX_APPS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${app}-$$(${CUT} -w -f3 ${WRKSRC}/lib/${app}/vsn.mk)
	${FIND} ${WRKSRC}/lib/${app} -type d -empty -delete
.for dir in src include priv ebin
	cd ${WRKSRC}/lib/${app} && if [ -d ${dir} ]; then \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${app}-$$(${CUT} -w -f3 vsn.mk); \
	fi
.endfor
.endfor

.include <bsd.port.mk>
