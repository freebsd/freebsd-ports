# New ports collection makefile for:	Q3 Mod: Weapons Factory Arena
# Date created:				Sun Jun  3 15:03:11 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	wfa
PORTVERSION=	3.5b
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTFILES=	WFA35Engine.zip WFA35MapPack1.zip WFA35MapPack2.zip \
		WFA_v35b.zip 35b_mappack1.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: Weapons Factory Arena

NO_PACKAGE=	"Package will be 138MB, set FORCE_PACKAGE if you really want to build it"

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

post-extract:
	@${RM} ${WRKSRC}/help/BobWFACfgV236.exe

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in EnglishRadioHelp help
	@${CP} -R ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
