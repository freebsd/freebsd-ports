PORTNAME=	stamp
PORTVERSION=	2.0.8
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Adds a graphical, configurable timestamp to a grayscale image
WWW=		https://stamp.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	historical tool, use imagemagick instead
EXPIRATION_DATE=	2025-12-31

USES=		jpeg localbase
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/share/stamp#${DATADIR}#' \
		${WRKSRC}/configure

.include <bsd.port.mk>
