# Created by: Pete Fritchman <petef@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synaesthesia
PORTVERSION=	2.4
PORTREVISION=	5
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/synaesthesia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphical music representation program

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}
USE_SDL=	sdl

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,stdint\.h,inttypes.h,' ${WRKSRC}/*.c?
	@${REINPLACE_CMD} -e 's,int16_t,u_int16_t,' ${WRKSRC}/sound.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
