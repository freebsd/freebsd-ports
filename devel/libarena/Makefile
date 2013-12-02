# Created by: ijliao
# $FreeBSD$

PORTNAME=	libarena
PORTVERSION=	0.3.6
CATEGORIES=	devel
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Custom Memory Allocator Interface

LICENSE=	MIT

USES=		gmake

PLIST_FILES=	include/arena/align.h \
		include/arena/arena.h \
		include/arena/pool.h \
		include/arena/proto.h \
		include/arena/rbits.h \
		include/arena/util.h \
		lib/libarena.a
PLIST_DIRS=	include/arena

post-patch:
.for i in Epilogue.mk Prologue.mk
	@${REINPLACE_CMD} -e \
		'/!=/s|^|#|' ${WRKSRC}/mk/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|:=|?=|' ${WRKSRC}/mk/Variables.mk

.include <bsd.port.mk>
