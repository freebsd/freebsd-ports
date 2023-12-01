PORTNAME=	gdb
PORTVERSION=	${GDB_RELEASE}
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT=	Meta-port for the default version of the GDB Debugger
WWW=		https://cheribsd.org/
DESCR=		${.CURDIR}/../gdb/pkg-descr

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb-cheri

.include "${.CURDIR}/../gdb-cheri/Makefile.snapshot"
.include <bsd.port.mk>
