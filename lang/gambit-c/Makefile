# Created by: Rob Zinkov
# $FreeBSD$

PORTNAME=	gambit-c
PORTVERSION=	4.9.3
DISTVERSIONPREFIX=	v
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Gambit programming system where the compiler generates portable C code

LICENSE=	APACHE20 LGPL21
LICENSE_COMB=	dual

USES=		compiler gmake
USE_GITHUB=	yes
GH_ACCOUNT=	gambit
GH_PROJECT=	gambit
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-single-host \
		--enable-gcc-opts \
		--docdir=${DOCSDIR} \
		--includedir=${PREFIX}/include/gambit-c \
		--libdir=${PREFIX}/lib/gambit-c \
		--enable-compiler-name=gsc-gambit \
		--enable-interpreter-name=gsi-gambit
MAKEFILE=	makefile
USE_LDCONFIG=	${PREFIX}/lib/gambit-c

INFO=		gambit

OPTIONS_DEFINE=	DOCS GCC
OPTIONS_DEFAULT=GCC

GCC_DESC=	Build with GCC from ports

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGCC}
USE_GCC=	yes
.endif

post-patch:
.for i in makefile.in gsc/makefile.in gsi/makefile.in lib/makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}| ; \
		 s|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gs[ci]-gambit

.include <bsd.port.post.mk>
