PORTNAME=	gambit-c
PORTVERSION=	4.9.6
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	lang

GAMBIT_VERSION=	409006

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Gambit programming system where the compiler generates portable C code
WWW=		https://gambitscheme.org

LICENSE=	APACHE20 LGPL21
LICENSE_COMB=	dual

USES=		compiler gmake
USE_GITHUB=	yes
GH_ACCOUNT=	gambit
GH_PROJECT=	gambit
USE_LDCONFIG=	${PREFIX}/lib/gambit-c
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--enable-compiler-name=gsc-gambit \
		--enable-gcc-opts \
		--enable-interpreter-name=gsi-gambit \
		--enable-single-host \
		--includedir=${PREFIX}/include/gambit-c \
		--libdir=${PREFIX}/lib/gambit-c
MAKEFILE=	makefile

INFO=		gambit
PLIST_SUB=	GAMBIT_VERSION=${GAMBIT_VERSION}

OPTIONS_DEFINE=		DOCS

.include <bsd.port.pre.mk>

post-patch:
.for i in makefile.in gsc/makefile.in gsi/makefile.in lib/makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}| ; \
		 s|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gs[ci]-gambit

.include <bsd.port.post.mk>
