# New ports collection makefile for:	global
# Date created:		20 June 2000
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	global
PORTVERSION=	3.55
CATEGORIES=	devel
MASTER_SITES=	http://www.tamacom.com/unix/

MAINTAINER=	chuckr@freebsd.org

MAKE_FLAGS+=	INCDIR=$(LOCALBASE)/include LIBDIR=$(LOCALBASE)/lib BINDIR=$(LOCALBASE)/bin SHAREDIR=$(LOCALBASE)

MAN1=		htags.1 btreeop.1 gtags.1 global.1 gctags.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
