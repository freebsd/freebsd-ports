# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	7kaa
PORTVERSION=	2.14.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/skfans/7KAA%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Seven Kingdoms: Ancient Adversaries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenet.so:net/enet

USES=		gmake localbase openal:al tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls # no translations ATM
USE_SDL=	sdl2

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
