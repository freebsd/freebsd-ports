# New ports collection makefile for:	dhex
# Date created:				23 Jan 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dhex
PORTVERSION=	0.62
CATEGORIES=	editors
MASTER_SITES=	http://www.dettus.net/dhex/ \
		CRITICAL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A ncurses-based hex-editor with diff mode

LICENSE=	GPLv2
PLIST_FILES=	bin/dhex

MAKE_JOBS_SAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
