# Created by: Pete Fritchman <petef@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synaesthesia
PORTVERSION=	2.4
PORTREVISION=	7
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/synaesthesia/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphical music representation program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}
USE_SDL=	sdl

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

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
