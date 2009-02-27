# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2008.710
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/alienarena/Files/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}2008-linux20080603

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alien Arena 2008 (data)

USE_ZIP=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 185MB, set FORCE_PACKAGE if you want it
WRKSRC=		${WRKDIR}/${PORTNAME}2008

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
