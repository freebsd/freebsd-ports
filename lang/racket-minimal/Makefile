# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PKGNAMESUFFIX=	-minimal
PORTVERSION=	6.0.1
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/

DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}-src
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		RACKET_PLACES
RACKET_PLACES_DESC=	Enable Places
OPTIONS_DEFAULT=	RACKET_PLACES

CONFLICTS=	racket-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-pthread \
		--enable-lt=${LIBTOOL}

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MANUAL_PACKAGE_BUILD=	i386 requires kern.maxdsiz="640M" to build
.endif

LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi

.if ${PORT_OPTIONS:MRACKET_PLACES}
CONFIGURE_ARGS+=	--enable-places
.else
CONFIGURE_ARGS+=	--disable-places
.endif

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src
USES=		iconv libtool tar:tgz
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

.include <bsd.port.post.mk>
