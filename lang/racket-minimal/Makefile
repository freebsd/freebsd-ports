# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PORTVERSION=	6.10
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

BROKEN_i386=		fails to build: Seg fault (internal error) at 0x606060a
BROKEN_powerpc64=	fails to build: jit.c: 'JIT_LOCAL4' undeclared (first use in this function)
NOT_FOR_ARCHS=		aarch64 aarch64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this arch

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
