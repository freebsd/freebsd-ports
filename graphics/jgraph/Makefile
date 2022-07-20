PORTNAME=	jgraph
PORTVERSION=	8.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://web.eecs.utk.edu/~plank/plank/jgraph/
DISTFILES=	${PORTNAME}.shar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates postscript graphs

EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAKE_ENV+=	DATADIR=${DATADIR}
CFLAGS+=	-Wno-return-type

.include <bsd.port.mk>
