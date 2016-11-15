# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PORTVERSION=	6.7
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/
PKGNAMESUFFIX=	-minimal
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}-src-builtpkgs
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment

LICENSE=	LGPL3

LIB_DEPENDS=	libffi.so:devel/libffi

BROKEN_aarch64=	does not build: error: Unported platform
BROKEN_sparc64=	does not build

MAKE_JOBS_UNSAFE=yes

CONFLICTS=	racket-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-enable-libffi --enable-pthread --enable-places --enable-shared
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src
PATCH_WRKSRC=	${WRKDIR}/racket-${PORTVERSION}
USES=		iconv libtool tar:tgz
USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""
OPTIONS_DEFINE=	FUTURES
OPTIONS_DEFAULT=FUTURES

OPTIONS_DEFINE_amd64=	JIT
OPTIONS_DEFINE_i386=	JIT
OPTIONS_DEFAULT_amd64=	JIT
OPTIONS_DEFAULT_i386=	JIT

FUTURES_DESC=	Enable futures
JIT_DESC=	Enable JIT compiler
JIT_CFLAGS=	-msse -msse2 -mfpmath=sse

FUTURES_CONFIGURE_ENABLE=	futures
JIT_CONFIGURE_ENABLE=	jit

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
