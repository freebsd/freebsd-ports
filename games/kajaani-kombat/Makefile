# New Ports collection makefile for:	kajaani-kombat
# Date created:		2012-04-27
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	kombat
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	http://kombat.kajaani.net/dl/
PKGNAMEPREFIX=	kajaani-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Kajaani Kombat is a funny multiplayer game... and much more

LICENSE=	GPLv2

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
USE_SDL=	sdl image mixer net ttf
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/kajaani-kombat \
		bin/kajaani-kombat-server \
		share/pixmaps/kajaani-kombat.png

PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE})
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} server)

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./kajaani-kombat\n" > ${WRKDIR}/kajaani-kombat.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/kajaani-kombat.sh ${PREFIX}/bin/kajaani-kombat
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./kajaani-kombat-server\n" > ${WRKDIR}/kajaani-kombat-server.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/kajaani-kombat-server.sh ${PREFIX}/bin/kajaani-kombat-server
# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/kajaani-kombat ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/kajaani-kombat-server ${DATADIR}

post-install:
# Data
.if !defined (NOPORTDATA)
	${INSTALL_DATA} ${WRKSRC}/*.png ${WRKSRC}/*.ogg ${WRKSRC}/*.ttf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.png ${PREFIX}/share/pixmaps/${PKGNAMEPREFIX}${PORTNAME}.png
.endif

# Documentations
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
