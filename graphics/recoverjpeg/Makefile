# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	recoverjpeg
PORTVERSION=	2.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recoverjpeg tries to recover JFIF (JPEG) pictures from a peripheral

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:textproc/hs-pandoc
RUN_DEPENDS=	exif:graphics/exif \
		identify:graphics/ImageMagick

USES=		autoreconf python shebangfix
GNU_CONFIGURE=	yes

SHEBANG_FILES=	scripts/remove-duplicates

USE_GITHUB=	yes
GH_ACCOUNT=	samueltardieu

.include <bsd.port.mk>
