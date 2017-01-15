# $FreeBSD$

PORTNAME=	traindirector
PORTVERSION=	3.6
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.backerstreet.com/traindir/
DISTNAME=	tdir36src

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Train controller simulation

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes

USES=		gmake zip
USE_GNOME=	gtk20

USE_WX=		2.8
WX_COMPS=	wx:lib
WX_UNICODE=	yes

DESKTOP_ENTRIES="Train Director" "${COMMENT}" "" "traindir3" \
		"Game;Simulation;StrategyGame;" false

PLIST_FILES=	bin/traindir3

MAKEFILE=	Makefile.fc9

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1200017
BROKEN=		Fails to compile with clang 3.9.x and later
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traindir3 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
