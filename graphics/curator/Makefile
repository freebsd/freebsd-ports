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

OPTIONS_DEFINE=	PIL
PIL_DESC=	Use Python Imaging Library instead of ImageMagick

PLIST_FILES=	man/man1/curator.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPIL}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=0:graphics/py-imaging
.else
RUN_DEPENDS=	convert:graphics/ImageMagick
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/curator.1 ${STAGEDIR}${PREFIX}/man/man1/curator.1

.include <bsd.port.mk>
