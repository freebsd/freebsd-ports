# New ports collection makefile for:	aalib
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	aalib
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://horac.ta.jcu.cz/pub/aa/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org

USE_AUTOMAKE=	yes
AUTOMAKE=	automake -a -i
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_X11)
USE_XLIB=	yes
CONFIGURE_ARGS=	--x-includes="${X11BASE}/include" \
		--x-libraries="${X11BASE}/lib"
.else
CONFIGURE_ARGS=	--with-x=no
.endif

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g;" ${WRKSRC}/configure.in

.include <bsd.port.mk>
