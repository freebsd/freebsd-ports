# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PORTVERSION=	7.5
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-builtpkgs
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

IGNORE_powerpc64=	./lightning/lightning.h:81:2: GNU lightning does not support the current target
BROKEN_i386=		segfaults during build

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libffi.so:devel/libffi \
		libpng.so:graphics/png

USES=		gnome iconv jpeg libtool localbase sqlite tar:tgz
USE_GNOME=	cairo pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libffi \
		--enable-places \
		--enable-pthread \
		--mandir=${MANDIRS}
WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src
PATCH_WRKSRC=	${WRKDIR}/racket-${PORTVERSION}
USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""
MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	racket-minimal-[0-9]*

OPTIONS_DEFINE=		DOCS FUTURES
OPTIONS_DEFAULT=	FUTURES

OPTIONS_DEFINE_amd64=	JIT
OPTIONS_DEFINE_i386=	JIT
OPTIONS_DEFAULT_amd64=	JIT
OPTIONS_DEFAULT_i386=	JIT

FUTURES_DESC=	Enable futures
JIT_DESC=	Enable JIT compiler

FUTURES_IMPLIES=		JIT
FUTURES_CONFIGURE_ENABLE=	futures
JIT_CONFIGURE_ENABLE=		jit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJIT} && ${ARCH} == "amd64"
CFLAGS+=	-msse -msse2 -mfpmath=sse
.endif

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete
	${REINPLACE_CMD} -e "s@${STAGEDIR}@@" ${STAGEDIR}${PREFIX}/share/applications/*.desktop

.include <bsd.port.mk>
