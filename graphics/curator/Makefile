# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	curator
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	graphics www python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Static Image Gallery Generator for web or CD-ROM galleries

USES=		python
USE_PYTHON=	distutils autoplist

PLIST_FILES=	man/man1/curator.1.gz

RUN_DEPENDS=	convert:graphics/ImageMagick

post-install:
	${INSTALL_MAN} ${FILESDIR}/curator.1 ${STAGEDIR}${PREFIX}/man/man1/curator.1

.include <bsd.port.mk>
