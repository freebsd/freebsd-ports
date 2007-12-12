# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.610
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.simtel.com/pub/gamezone/31/5/17/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}2007-20071011-linux

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (data)

USE_ZIP=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 185MB, set FORCE_PACKAGE if you want it
WRKSRC=		${WRKDIR}/${PORTNAME}2007

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC} && ${RM} arena/*.so data1/*.so

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R arena botinfo data1 ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA} ${WRKSRC}/aa.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
