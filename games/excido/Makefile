# New ports collection makefile for:	excido
# Date created:				19 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	excido
PORTVERSION=	0.1.5c
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/excido/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alejandro@varnet.biz
COMMENT=	A portable fast-paced 3d shooter

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		physfs-1.0.1:${PORTSDIR}/devel/physfs

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GL=		yes
USE_SDL=	image sdl ttf

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
			s|%%CFLAGS%%|${CFLAGS}| ; \
			s|%%DATADIR%%|${DATADIR}| ; \
			s|%%X11BASE%%|${X11BASE}|' \
				${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
