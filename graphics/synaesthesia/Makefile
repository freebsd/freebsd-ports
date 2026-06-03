PORTNAME=	synaesthesia
PORTVERSION=	2.4
PORTREVISION=	7
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/synaesthesia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphical music representation program
WWW=		https://www.logarithmic.net/pfh/synaesthesia

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake sdl
USE_CXXSTD=	c++14
USE_SDL=	sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,stdint\.h,inttypes.h,' ${WRKSRC}/*.c?
	@${REINPLACE_CMD} -e 's,int16_t,u_int16_t,' ${WRKSRC}/sound.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
