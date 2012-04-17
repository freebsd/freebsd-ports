# New ports collection Makefile for:    DrScheme
# Date created:         21 Jun 2001
# Whom:                 Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	racket-textual
PORTVERSION=	5.2.1
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.racket-lang.org/installers/${PORTVERSION}/${PORTNAME}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/${PORTNAME}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/${PORTNAME}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/${PORTNAME}/ \
		ftp://infogroep.be/pub/racket/installers/${PORTVERSION}/${PORTNAME}/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/${PORTVERSION}/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-unix
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

MAKE_JOBS_UNSAFE=yes

OPTIONS=	RACKET_PLACES	"Enable Places" ON

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared --enable-pthread \
			--enable-lt=${LIBTOOL}
CONFIGURE_SCRIPT=	../configure

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
MANUAL_PACKAGE_BUILD=	i386 requires kern.maxdsiz="640M" to build
.endif

LIB_DEPENDS+=	ffi.5:${PORTSDIR}/devel/libffi

.if defined(WITH_RACKET_PLACES)
CONFIGURE_ARGS+=	--enable-places
.else
CONFIGURE_ARGS+=	--disable-places
.endif

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/build
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:env

MAN1=   mzc.1 mzscheme.1 racket.1 raco.1 setup-plt.1

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
