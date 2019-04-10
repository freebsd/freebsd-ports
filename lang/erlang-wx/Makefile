# $FreeBSD$

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	19.3.6.13
PORTEPOCH=	1
CATEGORIES=	lang parallel
PKGNAMESUFFIX=	-wx
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang bindings for wxWindows

LICENSE=	APACHE20

BUILD_DEPENDS=	erlc:lang/erlang
RUN_DEPENDS=	erl:lang/erlang

USES=		autoreconf:build gl gmake perl5
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_GL=		gl glu
USE_PERL5=	build
USE_WX=		2.8+

WX_COMPS=	wx contrib

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	DEBUGGER_VERSION=${debugger_VSN} \
		ET_VERSION=${et_VSN} \
		OBSERVER_VERSION=${observer_VSN} \
		WX_VERSION=${wx_VSN} \
		CONFIGURE_TARGET=${CONFIGURE_TARGET}

debugger_VSN=	1.8
et_VSN=		1.6
observer_VSN=	4.2.1
wx_VSN=		1.8

ERLANG_REL=	19.3

CONFIGURE_ARGS+=--enable-threads --without-odbc --without-javac --with-wx-config=${WX_CONFIG}

pre-configure:
	@cd ${WRKSRC} && ./otp_build autoconf

do-build:
.for app in wx debugger et observer
	cd ${WRKSRC}/lib/${app} && /usr/bin/env ERL_LIBS=${WRKSRC}/lib ${GMAKE} ERL_TOP=${WRKSRC} TARGET=${CONFIGURE_TARGET}
.endfor
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/erl_gl.so
	${STRIP_CMD} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/wxe_driver.so
	${MV} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}/*.so ${WRKSRC}/lib/wx/priv
	${RMDIR} ${WRKSRC}/lib/wx/priv/${CONFIGURE_TARGET}

do-install:
.for app in wx debugger et observer
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${app}-${${app}_VSN}
	${FIND} ${WRKSRC}/lib/${app} -type d -empty -delete
.for dir in src include priv ebin
	cd ${WRKSRC}/lib/${app} && if [ -d ${dir} ]; then \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${app}-${${app}_VSN}; \
	fi
.endfor
.endfor

.include <bsd.port.mk>
