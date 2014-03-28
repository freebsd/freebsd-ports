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

USES=		dos2unix zip
DOS2UNIX_GLOB=	${PORTDOCS}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q1DIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in Autoexec.cfg PROGS.DAT
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/${f:L}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in B08chg.txt Dedserv.txt Reaprb80.txt Skinspec.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f:L}
.endfor

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.mk>
