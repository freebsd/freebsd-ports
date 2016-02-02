# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	tads
PORTVERSION=	2.5.9
CATEGORIES=	games lang
MASTER_SITES=	LOCAL/kris
DISTNAME=	tads23-unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TADS compiler/interpreter for interactive fiction

LICENSE=	TADS
LICENSE_NAME=	TADS FREEWARE SOURCE CODE LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS=	frobtads-1.*

USES=		ncurses
WRKSRC=		${WRKDIR}/tads-3.0.8/tads2
DATADIR=	${PREFIX}/share/tads2

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tads2
.for i in tadsc tadsr tdb
	${INSTALL_PROGRAM} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in adv.t std.t gameinfo.t
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/share/tads2
.endfor

.include <bsd.port.mk>
