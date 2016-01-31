# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rote
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple library for VT102 terminal emulation

GNU_CONFIGURE=	yes
USES=		gmake ncurses
USE_LDCONFIG=	yes

PLIST_FILES=	bin/rote-config include/rote/rote.h \
		lib/librote.so.${PORTVERSION} lib/librote.so.0 lib/librote.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librote.so

.include <bsd.port.mk>
