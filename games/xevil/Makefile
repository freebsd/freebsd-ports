# New ports collection makefile for:   xevil
# Date created:        7 November 2000
# Whom:    Göran Runfeldt <goranrunfeldt@home.se>
#
# $FreeBSD$
#

PORTNAME=	xevil
PORTVERSION=	2.02
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.xevil.com/stable/
DISTNAME=	xevilsrc${PORTVERSION}

MAINTAINER=	goranrunfeldt@home.se

USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_XPM=	yes
ALL_TARGET=	freebsd

# I'm not sure if this should be here
.if (${MACHINE} == "alpha")
CFLAGS+="-DXEVIL_KEYSET=UIalpha"
.endif

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

do-extract:
	@unzip -aqo ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

post-extract:
	@${MV} -f ${WRKDIR}/${DISTNAME}/makefile ${WRKDIR}/${DISTNAME}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/FREEBSD/xevil ${PREFIX}/bin/xevil
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xevil/instructions
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/xevil
	${INSTALL_DATA} ${WRKSRC}/instructions/* \
	${PREFIX}/share/doc/xevil/instructions
.endif

.include <bsd.port.mk>
