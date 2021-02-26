# $FreeBSD$

PORTNAME=	erlang
DISTVERSIONPREFIX=	OTP-
DISTVERSION=	21.3.8.21
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	lang parallel
PKGNAMESUFFIX=	-wx
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang bindings for wxWindows

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=21.3.8:lang/erlang
RUN_DEPENDS=	erlang>=21.3.8:lang/erlang

USES=		autoreconf:build gl gmake perl5 xorg
USE_GITHUB=	yes
GH_PROJECT=	otp
USE_GL=		gl glu
USE_PERL5=	build
USE_WX=		3.1+

WX_COMPS=	wx

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

WX_APPS=	wx debugger et observer

CONFIGURE_ARGS+=--enable-threads --without-odbc --without-javac --with-wx-config=${WX_CONFIG}

pre-configure:
	@cd ${WRKSRC} && ./otp_build autoconf

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
