# Created by: wolman@cs.washington.edu
# $FreeBSD$

PORTNAME=	jgraph
PORTVERSION=	8.3
CATEGORIES=	graphics
MASTER_SITES=	http://web.eecs.utk.edu/~plank/plank/jgraph/
DISTFILES=	${PORTNAME}.shar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates postscript graphs

NO_LATEST_LINK=	yes
EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes
MAN1=		jgraph.1
MAKEFILE=	makefile

MAKE_ENV+=	DATADIR=${DATADIR}

CFLAGS+=	-Wno-return-type

NO_STAGE=	yes
.include <bsd.port.mk>
