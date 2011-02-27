# New ports collection makefile for:	yace
# Date created:				2008-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	yace
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Corewars Evolver

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKDIR}/src
MAKEFILE=	makefile
ALL_TARGET=	#

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|CCFLAGS =|& ${CFLAGS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/bin && ${CP} -r bench testset yace.cfg ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
