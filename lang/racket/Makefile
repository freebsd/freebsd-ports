# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PORTVERSION=	6.0.1
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		RACKET_PLACES
RACKET_PLACES_DESC=	Enable Places
OPTIONS_DEFAULT=	RACKET_PLACES

CONFLICTS=	racket-minimal-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-pthread \
		--enable-lt=${LIBTOOL}

.include <bsd.port.options.mk>

.if defined(WITHOUT_X11)
IGNORE=		requires X11; use lang/racket-textual instead
.endif

.if ${ARCH} == "i386"
MANUAL_PACKAGE_BUILD=	i386 requires kern.maxdsiz="640M" to build
.endif

LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi		\
		libcairo.so:${PORTSDIR}/graphics/cairo	\
		libjpeg.so:${PORTSDIR}/graphics/jpeg	\
		libpng15.so:${PORTSDIR}/graphics/png

.if ${PORT_OPTIONS:MRACKET_PLACES}
CONFIGURE_ARGS+=	--enable-places
.else
CONFIGURE_ARGS+=	--disable-places
.endif

# Force the "configure" script to look in $LOCALBASE for -lpng and -ljpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src
USES=		iconv libtool
USE_LDCONFIG=	yes
USE_GNOME=	pango
USE_SQLITE=	3

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

post-install:
	${REINPLACE_CMD} -e "s@${STAGEDIR}@@" ${STAGEDIR}${PREFIX}/share/applications/*.desktop
	${RM} ${STAGEDIR}${PREFIX}/share/applications/*.bak

.include <bsd.port.post.mk>
