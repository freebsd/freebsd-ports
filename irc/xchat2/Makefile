# New ports collection makefile for:	xchat2
# Date created:			17 Aug 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xchat2
PORTVERSION=	1.9.8
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://xchat.org/files/source/1.9/ \
		http://xchat.linuxpower.org/files/source/1.9/
DISTNAME=	xchat-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-nls \
		--enable-ipv6 \
		--enable-perl

.include <bsd.port.pre.mk>

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--enable-socks
.endif

# openssl in now default in configure

.if defined(WITH_PYTHON)
USE_PYTHON=    yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB=	PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB=	PYTHON="@comment "
.endif

pre-everything::
.if !defined(WITH_PYTHON) || !defined(WITH_SOCKS)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "WITH_PYTHON=yes for Python support"
.endif
.if !defined(WITH_SOCKS)
	@${ECHO_MSG} "WITH_SOCKS=yes for SOCKS5 proxy support"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS}|g;' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
