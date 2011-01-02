# New ports collection makefile for:	tds
# Date created:		17 Jan 2003
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tads
PORTVERSION=	2.5.9
CATEGORIES=	games lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
#		http://www.ifarchive.org/if-archive/programming/tads2/source/
MASTER_SITE_SUBDIR=kris
DISTNAME=	tads23-unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TADS compiler/interpreter for interactive fiction

WRKSRC=		${WRKDIR}/tads-3.0.8/tads2

do-install:
	${MKDIR} ${PREFIX}/share/tads2
.for i in tadsc tadsr tdb
	${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor
.for i in adv.t std.t gameinfo.t
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/tads2
.endfor

.include <bsd.port.mk>
