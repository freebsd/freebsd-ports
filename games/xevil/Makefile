# New ports collection makefile for:   xevil
# Date created:        7 November 2000
# Whom:    Göran Runfeldt <goranrunfeldt@home.se>
#
# $FreeBSD$
#

PORTNAME=	xevil
PORTVERSION=	2.02.r2
CATEGORIES=	games
MASTER_SITES=	http://www.xevil.com/download/stable/
DISTNAME=	xevilsrc${PORTVERSION:S/.r/r/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast-action, networked, anti-social, kill-everything game

USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_XPM=	yes
ALL_TARGET=	freebsd

.include <bsd.port.pre.mk>

# I'm not sure if this should be here
.if (${MACHINE} == "alpha")
CFLAGS+="-DXEVIL_KEYSET=UIalpha"
.endif

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
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

.include <bsd.port.post.mk>
