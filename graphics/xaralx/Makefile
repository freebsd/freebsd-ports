# New ports collection makefile for:	XaraLX
# Date created:				22 Mar 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XaraLX
PORTVERSION?=	0.4r798
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.xara.com/opensource/
DISTFILES?=	${PORTNAME}Src-${PORTVERSION}.tar.gz

MAINTAINER=	vd@FreeBSD.org
COMMENT?=	Top-tier vector/general purpose graphics program (recommended version)

#WXDEP=	${X11BASE}/libwx_baseu-2.6.so.0.3.1
WXDEP=	wxgtk2-unicode>=2.6.3
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		${WXDEP}:${PORTSDIR}/x11-toolkits/wxgtk26-unicode \
		${LOCALBASE}/bin/md5sum:${PORTSDIR}/archivers/dpkg \
		${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	dlmalloc.2:${PORTSDIR}/devel/libdlmalloc

USE_AUTOTOOLS=	autoconf:259:env aclocal:19:env automake:19:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-wx-config=wxgtk2u-2.6-config \
		--program-suffix=${PKGNAMESUFFIX}
PKGCONFIGS=atk fontconfig gdk-2.0 pango
CONFIGURE_ENV+=	CPPFLAGS_APPEND="`pkg-config --cflags ${PKGCONFIGS}` \
		-I${LOCALBASE}/include/atk-1.0/atk \
		-I${X11BASE}/include/gtk-2.0/gtk"

USE_GMAKE=	yes
USE_GCC=	3.4+

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64" && ${ARCH} != "powerpc"
BROKEN=	does not configure due to the lack of CDraw libraries for ${ARCH}
.endif

PROG=	XaraLX${PKGNAMESUFFIX}

PLIST_FILES=	bin/${PROG}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -f -s -i

.include <bsd.port.post.mk>
