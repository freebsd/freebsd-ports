# New ports collection makefile for:	urbanterror-data
# Date created:				2007-09-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	urbanterror
PORTVERSION=	4.1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.snt.utwente.nl/pub/games/urbanterror/full_install/linux_or_mac/
#		http://www.urbanterror.info/downloads/software/urt/${DISTNAME}${EXTRACT_SUFX}?download=direct\\\#
PKGNAMESUFFIX=	-data
DISTNAME=	UrbanTerror${PORTVERSION:S/.//g}

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Standalone realism based mod originally for Quake III Arena

USE_ZIP=	yes
NO_BUILD=	yes
#NO_PACKAGE=	Package will be 1GB; set FORCE_PACKAGE if you really want it
WRKSRC=		${WRKDIR}/UrbanTerror

DATADIR=	${Q3DIR}

.include "../quake3-data/Makefile.include"

post-extract:
	@cd ${WRKSRC}/q3ut4 && ${MV} readme${PORTVERSION:S/.//:C/\..*//}.txt ..

do-install:
	${MKDIR} ${DATADIR}/q3ut4
	${CP} -r ${WRKSRC}/q3ut4/* ${DATADIR}/q3ut4
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme${PORTVERSION:S/.//:C/\..*//}.txt \
		${DOCSDIR}/readme${PORTVERSION:S/.//g}.txt
.endif

.include <bsd.port.mk>
