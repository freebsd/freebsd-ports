# $FreeBSD$

PORTNAME=	libbpfjit
PORTVERSION=	g2019052401
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Just-in-Time compilation of bpf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENCE

USES=		gmake

USE_GITHUB=	yes
GH_TUPLE=	rmind:bpfjit:5fa111b:DEFAULT \
		zherczeg:sljit:849950a:sljit
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
CFLAGS+=	-I${WRKSRC_sljit}/sljit_src

PLIST_FILES=	lib/libbpfjit.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/libbpfjit.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
