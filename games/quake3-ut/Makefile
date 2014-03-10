# Created by: Patrick Li <pat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ut
PORTVERSION=	3.7
CATEGORIES=	games
MASTER_SITES=	http://bigfoot.morphos-team.net/misc/Quake3Mods/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	UrbanTerror${PORTVERSION:S/.//}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena mod: Urban Terror

NO_PACKAGE=	package will be 445MB, set FORCE_PACKAGE if you really want it

USES=		gmake zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.pk3 description.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.  for f in beta3.html radio_commands.txt readme*.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
