# New ports collection Makefile for:	aview
# Date created:		Dec 18 1997
# Whom:			frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	aview
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aa-project

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x=no

post-patch:
	@${PERL} -pi -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name '*.[ch]' | xargs ${PERL} -pi -e \
		's|<malloc.h>|<stdlib.h>|g' \

.include <bsd.port.mk>
