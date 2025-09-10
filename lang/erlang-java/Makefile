PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	26.2.5.15
PORTEPOCH=	1
CATEGORIES=	lang parallel java
PKGNAMESUFFIX=	-java
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang interface for Java
WWW=		https://www.erlang.org/

LICENSE=	APACHE20

RUN_DEPENDS=	erl:lang/erlang

USES=		autoreconf:build gmake java perl5
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_PERL5=	build

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads \
			--with-javac \
			--without-odbc \
			--without-wx
CONFIGURE_ENV+=		ac_cv_prog_JAVAC="${JAVAC}"
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	APP_VERSION=${APP_VERSION}

APP_VERSION=	1.14
APP_DIR=	${PREFIX}/lib/erlang/lib/jinterface-${APP_VERSION}

pre-configure:
	@if [ ! $$(${CAT} ${WRKSRC}/lib/jinterface/vsn.mk | ${GREP} -E "JINTERFACE_VSN *=" | ${CUT} -w -f3) = ${APP_VERSION} ]; then \
		${ECHO_MSG} "===>  APP_VERSION (${APP_VERSION}) in Makefile does not match value in lib/jinterface/vsn.mk"; exit 1; \
	fi

do-build:
	@${MKDIR} ${WRKSRC}/lib/jinterface/ebin
	cd ${WRKSRC}/lib/jinterface && ${GMAKE} ERL_TOP=${WRKSRC} TARGET=${CONFIGURE_TARGET}
	${RM} -r ${WRKSRC}/lib/jinterface/priv/com

do-install:
	@${MKDIR} ${STAGEDIR}${APP_DIR}
	@${MKDIR} ${STAGEDIR}${APP_DIR}/priv
	cd ${WRKSRC}/lib/jinterface && ${COPYTREE_SHARE} ebin ${STAGEDIR}${APP_DIR}
	cd ${WRKSRC}/lib/jinterface && ${COPYTREE_SHARE} java_src ${STAGEDIR}${APP_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/jinterface/priv/OtpErlang.jar ${STAGEDIR}${APP_DIR}/priv

.include <bsd.port.mk>
