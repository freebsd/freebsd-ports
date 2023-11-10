PORTNAME=	stamp
PORTVERSION=	2.0.8
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Adds a graphical, configurable timestamp to a grayscale image
WWW=		https://stamp.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		jpeg localbase
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/share/stamp#${DATADIR}#' \
		${WRKSRC}/configure

.include <bsd.port.mk>
