# New ports collection makefile for:	cvstrac
# Date created:				29 August 2002
# Whom:					Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	cvstrac
PORTVERSION=	1.1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cvstrac.org/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAINTAINER=	bms@FreeBSD.org
COMMENT=	Web-Based Bug And Patch-Set Tracking System For CVS

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2

USE_GMAKE=	yes

MAKE_ARGS=	SRCDIR=${WRKSRC} PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

NOMAN=
PLIST_FILES=	bin/cvstrac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvstrac ${PREFIX}/bin

.include <bsd.port.mk>
