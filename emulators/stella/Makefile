# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stella
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A multi-platform Atari 2600 VCS emulator

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	sdl
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|=sdl-config|="$$SDL_CONFIG"|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stella ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
