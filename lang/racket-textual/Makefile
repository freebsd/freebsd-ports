# New ports collection Makefile for:    DrScheme
# Date created:         21 Jun 2001
# Whom:                 Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	racket
PORTVERSION=	5.1.3
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.racket-lang.org/installers/${PORTVERSION}/racket/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/racket/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/racket/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/racket/ \
		ftp://infogroep.be/pub/racket/installers/${PORTVERSION}/racket/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/${PORTVERSION}/racket/
DISTNAME=	racket-${PORTVERSION}-src-unix
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	racket/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

MAKE_JOBS_UNSAFE=yes

OPTIONS=	X11	"X11 support"	ON

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared --enable-pthread \
			--enable-lt=${LIBTOOL}
CONFIGURE_SCRIPT=	../configure

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MANUAL_PACKAGE_BUILD=	i386 requires kern.maxdsiz="640M" to build
.endif

.if defined(WITH_X11)
USE_GNOME=	pango

LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo	\
		jpeg.11:${PORTSDIR}/graphics/jpeg	\
		png.6:${PORTSDIR}/graphics/png
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/cjpeg:${PORTSDIR}/graphics/jpeg			\
		${LOCALBASE}/libdata/pkgconfig/cairo.pc:${PORTSDIR}/graphics/cairo	\
		${LOCALBASE}/libdata/pkgconfig/libpng14.pc:${PORTSDIR}/graphics/png	\
		${LOCALBASE}/libdata/pkgconfig/pango.pc:${PORTSDIR}/x11-toolkits/pango
.endif

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src/build
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:env

MAN1=   drracket.1 gracket.1 mred.1 mzc.1 \
	mzscheme.1 plt-help.1 racket.1 \
	raco.1 setup-plt.1 tex2page.1

ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	ARCH=${ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${FIND} ${WRKDIR} -name *.orig -delete

.include <bsd.port.post.mk>
