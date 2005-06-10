# New ports collection makefile for:	ROTE
# Date created:				10 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rote
PORTVERSION=	0.2.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A simple library for VT102 terminal emulation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/rote-config include/rote/rote.h lib/librote.so.0.2.6 \
		lib/librote.so.0 lib/librote.so
PLIST_DIRS=	include/rote

.include <bsd.port.mk>
