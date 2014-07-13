# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket-minimal
PORTVERSION=	5.93
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		ftp://infogroep.be/pub/racket/installers/${PORTVERSION}/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

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
USES+=		iconv
USE_AUTOTOOLS=	libtool:env
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64

RACKET_PLIST=	${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

.include <bsd.port.post.mk>
