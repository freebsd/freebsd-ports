# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	reaper
PORTVERSION=	0.81
CATEGORIES=	games
MASTER_SITES=	http://www.mindspring.com/~win32ch/
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	reaprb81

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 1 bots

USES=		dos2unix
USE_ZIP=	yes
DOS2UNIX_GLOB=	${PORTDOCS}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q1DIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for f in Autoexec.cfg PROGS.DAT
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/${f:L}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.  for f in B08chg.txt Dedserv.txt Reaprb80.txt Skinspec.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f:L}
.  endfor
.endif

.include <bsd.port.mk>
