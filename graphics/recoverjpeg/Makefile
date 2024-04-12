PORTNAME=	recoverjpeg
PORTVERSION=	2.6.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://rfc1149.net/download/${PORTNAME}/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recoverjpeg tries to recover JFIF (JPEG) pictures from a peripheral
WWW=		https://rfc1149.net/devel/recoverjpeg.html

LICENSE=	GPLv2

RUN_DEPENDS=	exif:graphics/exif

USES=		magick:6,run python shebangfix
SHEBANG_FILES=	scripts/remove-duplicates
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
