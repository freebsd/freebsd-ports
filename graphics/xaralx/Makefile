# New ports collection makefile for:	XaraLX
# Date created:				22 Mar 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XaraLX
PORTVERSION?=	0.5r1175
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.xara.com/opensource/
DISTFILES?=	${PORTNAME}Src-${PORTVERSION}.tar.bz2

MAINTAINER=	vd@FreeBSD.org
COMMENT?=	Top-tier vector/general purpose graphics program (recommended version)

USE_BZIP2=	yes

#WXDEP=	${X11BASE}/libwx_baseu-2.6.so.0.3.1
WXDEP=	wxgtk2-unicode>=2.6.3
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${WXDEP}:${PORTSDIR}/x11-toolkits/wxgtk26-unicode \
		md5sum:${PORTSDIR}/archivers/dpkg \
		xml2-config:${PORTSDIR}/textproc/libxml2 \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS+=	${WXDEP}:${PORTSDIR}/x11-toolkits/wxgtk26-unicode
LIB_DEPENDS+=	dlmalloc.2:${PORTSDIR}/devel/libdlmalloc \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	autoconf:259:env aclocal:19:env automake:19:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2u-2.6-config \
		--program-suffix=${PKGNAMESUFFIX}
PKGCONFIGS=atk fontconfig gdk-2.0 pango
CONFIGURE_ENV+=	CPPFLAGS_APPEND="`pkg-config --cflags ${PKGCONFIGS}` \
		-I${LOCALBASE}/include/atk-1.0/atk \
		-I${X11BASE}/include/gtk-2.0/gtk"
# we're using dlmalloc because the stock libc does not have malloc_usable_size()
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -ldlmalloc"

USE_GMAKE=	yes
# add wxOil with -I- appended to it before any other -I stuff, see below
MAKE_ENV+=	INCLUDES="-I../wxOil -I- -I${LOCALBASE}/include/dlmalloc"

USE_GCC=	3.4+

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64" && ${ARCH} != "powerpc"
BROKEN=	does not configure due to the lack of CDraw libraries for ${ARCH}
.endif

PROG=	XaraLX${PKGNAMESUFFIX}

PLIST_FILES=	bin/${PROG}

# we need to strip wxOil from the include path because it contains file
# named strings.h which when included by /usr/include/string.h results
# in a complete mess
post-patch:
	${REINPLACE_CMD} -E -e 's|-I[^[:space:]]*/wxOil[[:space:]]||g' \
		${WRKSRC}/Makefile.am

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -f -s -i

.include <bsd.port.post.mk>
