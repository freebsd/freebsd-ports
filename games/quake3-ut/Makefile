# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	3.7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.snt.utwente.nl/pub/games/urbanterror/
DISTNAME=	urbanTerror${PORTVERSION:S/.//}_full

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Quake III Arena Mod: Urban Terror

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.pk3 description.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in beta3.html radio_commands.txt readme*.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
