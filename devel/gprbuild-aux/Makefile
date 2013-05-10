# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	gprbuild-aux
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/

MAINTAINER=	draco@marino.st
COMMENT=	Adacore multi-language software build tool

DEPRECATED=	Deprecated in favour of devel/gprbuild
EXPIRATION_DATE=	2013-06-10

BROKEN=		Does not build with recent ada toolchain rework

BUILD_DEPENDS=	gnat-aux>=20101204:${PORTSDIR}/lang/gnat-aux
BUILD_DEPENDS+=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada

EXAMPLESDIR=	share/examples/gprbuild
DOCSDIR=	share/doc/gprbuild
SNAPSHOT=	20101120
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
CC=		gnatgcc
MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
