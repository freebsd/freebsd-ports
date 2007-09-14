# New ports collection makefile for:	urbanterror
# Date created:				2007-09-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	urbanterror
PORTVERSION=	4.0
CATEGORIES=	games
MASTER_SITES=	http://mirrormaid.yi.org/ \
		http://mrsentry.net/release/ \
		http://outlands.quaddown.org/files/ \
		ftp://ftp.snt.utwente.nl/pub/games/urbanterror/ \
		ftp://ftp.vectranet.pl/pub/gry/UrbanTerror/
DISTNAME=	UrbanTerror${PORTVERSION:S/.//}_full

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Standalone realism based mod originally for Quake III Arena

DEPRECATED=	moved to games/urbanterror-data to maintain consistency

USE_ZIP=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 560MB; set FORCE_PACKAGE if you really want it
WRKSRC=		${WRKDIR}/q3ut4

DATADIR=	${Q3DIR}/q3ut4

post-extract:
	@cd ${WRKSRC} && ${MV} readme40.txt ..

do-install:
	${MKDIR} ${DATADIR}
	${CP} -r ${WRKSRC}/* ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme40.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.mk>
