# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	7kaa
PORTVERSION=	2.14.5
CATEGORIES=	games
MASTER_SITES=	SF/skfans/7KAA%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Seven Kingdoms: Ancient Adversaries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenet.so:net/enet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-nls # no translations ATM
USES=		gmake openal:al tar:xz
USE_SDL=	sdl2

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} -f ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
