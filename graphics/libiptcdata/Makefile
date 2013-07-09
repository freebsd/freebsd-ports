# New ports collection makefile for:	libiptcdata
# Date created:				3rd December 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiptcdata
PORTVERSION=	1.0.4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating IPTC metadata stored in image files

USE_AUTOTOOLS=	libtool
USES=		pkgconfig iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/libiptcdata/Makefile.in

.include <bsd.port.mk>
