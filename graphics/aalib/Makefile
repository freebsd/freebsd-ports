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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aa-project

MAINTAINER=	ports@FreeBSD.org

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
	@${PERL} -pi -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name '*.[ch]' \! -name acconfig.h \) \
		| xargs ${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
