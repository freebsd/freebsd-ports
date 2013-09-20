# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rote
PORTVERSION=	0.2.8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple library for VT102 terminal emulation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/rote-config include/rote/rote.h \
		lib/librote.so.${PORTVERSION} lib/librote.so.0 lib/librote.so
PLIST_DIRS=	include/rote

NO_STAGE=	yes
.include <bsd.port.mk>
