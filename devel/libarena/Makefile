PORTNAME=	libarena
PORTVERSION=	0.3.7
CATEGORIES=	devel
MASTER_SITES=	http://www.25thandclement.com/~william/projects/releases/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Custom Memory Allocator Interface

LICENSE=	MIT

USES=		gmake tar:tgz

PLIST_FILES=	include/arena/align.h \
		include/arena/arena.h \
		include/arena/pool.h \
		include/arena/proto.h \
		include/arena/rbits.h \
		include/arena/util.h \
		lib/libarena.a

post-patch:
.for i in Epilogue.mk Prologue.mk
	@${REINPLACE_CMD} -e \
		'/!=/s|^|#|' ${WRKSRC}/mk/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|:=|?=|' ${WRKSRC}/mk/Variables.mk
	${CP} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
