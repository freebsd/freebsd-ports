# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	fishsupper
PORTVERSION=	0.1.6
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Guide a cat across a series of rivers, jumping from log to log

BROKEN=		unfetchable

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:devel/boost-libs

BROKEN_powerpc64=	fails to compile: Log.h: expected initializer before '<' token

GNU_CONFIGURE=	yes
USES=		gl gmake localbase:ldflags sdl
USE_SDL=	sdl image mixer
USE_GL=		gl
USE_CXXSTD=	c++98

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Fish Supper" \
		"Guide a cat across a series of rivers, jumping from log to log" \
		"${DATADIR}/images/fs_image_30.png" \
		"fishsupper" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|std::tr1::shared_ptr|std::shared_ptr|g' ${WRKSRC}/src/*.h ${WRKSRC}/src/*.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
