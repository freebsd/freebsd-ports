# ex:ts=8
# Ports collection makefile for:	libarena
# Date created:			Apr 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libarena
PORTVERSION=	0.3.4
CATEGORIES=	devel
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Custom Memory Allocator Interface

USE_GMAKE=	yes

PLIST_FILES=	include/arena/align.h \
		include/arena/arena.h \
		include/arena/pool.h \
		include/arena/proto.h \
		include/arena/rbits.h \
		include/arena/util.h \
		lib/libarena.a
PLIST_DIRS=	include/arena

post-patch:
	@${REINPLACE_CMD} -E 's|^(PREFIX.*):=|\1?=|' \
		${WRKSRC}/mk/Variables.mk

.include <bsd.port.mk>
