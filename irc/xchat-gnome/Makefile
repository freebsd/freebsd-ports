# New ports collection makefile for:	xchat-gnome
# Date created:			04 May 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	xchat
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://navi.cx/releases/ \
		http://members.chello.nl/~g.mast/distfiles/
PKGNAMESUFFIX=	-gnome
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	An IRC client for GNOME 2 (development version)

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${XCHAT_VER}
XCHAT_VER=	2.0.8
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-nls \
		--enable-ipv6 \
		--enable-gnomefe

CONFLICTS=	xchat-1* xchat2-2*

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

# openssl in now default in configure

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl83.1:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=--enable-tcl=${LOCALBASE}/lib/tcl8.3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include/tcl8.3" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} \
		-L${LOCALBASE}/lib/tcl8.3"
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--enable-tcl=no
PLIST_SUB+=	TCL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${PERL_LEVEL} < 500600 || defined(WITHOUT_PERL)
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.endif

pre-everything::
.if !defined(WITH_PYTHON) || !defined(WITH_SOCKS) || !defined(WITH_TCL)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "WITH_PYTHON=yes for Python support"
.endif
.if !defined(WITH_SOCKS)
	@${ECHO_MSG} "WITH_SOCKS=yes for SOCKS5 proxy support"
.endif
.if !defined(WITH_TCL)
	@${ECHO_MSG} "WITH_TCL=yes for tcl support"
.endif
.if ${ARCH} != "amd64" && !defined(WITHOUT_PERL)
	@${ECHO_MSG} "WITHOUT_PERL=yes to disable Perl support"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|PY_LIBS=.*|PY_LIBS="-L\$$PY_EXEC_PREFIX/lib/python\$$PY_VER/config -lpython\$$PY_VER ${PTHREAD_LIBS} -lutil"|' \
		${WRKSRC}/configure

# Create plugins directory even when no plugins are installed
post-install:
	@${MKDIR} ${PREFIX}/lib/xchat/plugins

.include <bsd.port.post.mk>
