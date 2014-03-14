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

NO_PACKAGE=	package will be 200MB, set FORCE_PACKAGE if you really want it

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.options.mk>

post-extract:
	@${RM} ${WRKSRC}/help/BobWFACfgV236.exe

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} -a ${WRKSRC}/EnglishRadioHelp ${WRKSRC}/help ${DOCSDIR}
.endif

.include <bsd.port.mk>
