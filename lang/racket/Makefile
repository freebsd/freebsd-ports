# New ports collection Makefile for:    DrScheme
# Date created:         21 Jun 2001
# Whom:                 Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	racket
PORTVERSION=	5.0.2
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.racket-lang.org/installers/${PORTVERSION}/racket/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/racket/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/racket/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/racket/ \
		ftp://infogroep.be/pub/racket/installers/${PORTVERSION}/racket/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/${PORTVERSION}/racket/
DISTFILES=	racket-${PORTVERSION}-src-unix.tgz ${PLTPATCHES}
DIST_SUBDIR=	racket/${PORTVERSION}
EXTRACT_ONLY=	racket-${PORTVERSION}-src-unix.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

OPTIONS=	GRACKET	"Build GUI Racket"		ON

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared --enable-pthread \
			--enable-lt=${LIBTOOL}
CONFIGURE_SCRIPT=	../configure

.include <bsd.port.options.mk>

.if defined(WITHOUT_GRACKET)
CONFIGURE_ARGS+=	--disable-gracket
PLIST_SUB+=		GRACKET="@comment "
.else
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo	\
		jpeg.11:${PORTSDIR}/graphics/jpeg	\
		png.6:${PORTSDIR}/graphics/png

USE_XORG+=		xft x11 xrender xaw
USE_GL+=		yes
CONFIGURE_ARGS+=	--enable-xft --enable-gl --enable-xrender \
			--enable-cairo --with-x
PLIST_SUB+=		GRACKET=""
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src/build
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:env

MAN1=	drracket.1 drscheme.1 gracket.1 \
	mred.1 mzc.1 mzscheme.1 plt-help.1 \
	racket.1 raco.1 setup-plt.1 tex2page.1

ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	ARCH=${ARCH}

PLTPATCHES=	# none yet for this version

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
