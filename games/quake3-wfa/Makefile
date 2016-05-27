# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wfa
PORTVERSION=	3.5b
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTFILES=	WFA35Engine.zip WFA35MapPack1.zip WFA35MapPack2.zip \
		WFA_v35b.zip 35b_mappack1.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena mod: Weapons Factory Arena

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake3-data/Makefile.include"

post-extract:
	@${RM} ${WRKSRC}/help/BobWFACfgV236.exe

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.cfg *.pk3 ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${WRKSRC}/EnglishRadioHelp ${WRKSRC}/help ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
