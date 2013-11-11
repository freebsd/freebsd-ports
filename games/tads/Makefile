# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	tads
PORTVERSION=	2.5.9
CATEGORIES=	games lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris
DISTNAME=	tads23-unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TADS compiler/interpreter for interactive fiction

CONFLICTS=	frobtads-1.*

WRKSRC=		${WRKDIR}/tads-3.0.8/tads2
DATADIR=	share/tads2

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tads2
.for i in tadsc tadsr tdb
	${INSTALL_PROGRAM} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in adv.t std.t gameinfo.t
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/share/tads2
.endfor

.include <bsd.port.mk>
