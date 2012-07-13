# New ports collection makefile for:	opencvs
# Date created:				1 November 2008
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	opencvs
PORTVERSION=	20120705
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	johans

MAINTAINER=	johans@FreeBSD.org
COMMENT=	BSD-licensed CVS implementation

LICENSE=	BSD

WRKSRC=		${WRKDIR}/cvs
MANCOMPRESSED=	maybe

MAN1=		opencvs.1
MAN5=		opencvs.5
MAN7=		cvsintro.7

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man" \
		CATDIR="${MANPREFIX}/man/man"

PLIST_FILES=	bin/opencvs

.include <bsd.port.mk>
