# New ports collection makefile for:	Mesa3 for Linux compat
# Date created:		May 18 2000
# Whom:			Masahiro TAKEMURA
#
# $FreeBSD$
#

PORTNAME=		mesa
PORTVERSION=		3.4.2
PORTREVISION=		1
CATEGORIES=		graphics linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
PKGNAMEPREFIX=		linux_
DISTFILES=		MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
			MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		mastake@msel.t.u-tokyo.ac.jp

BUILD_DEPENDS=	${LINUXBASE}/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/bin/gcc:${PORTSDIR}/devel/linux_devtools

USE_BZIP2=		yes
ONLY_FOR_ARCHS=		i386
USE_LINUX_PREFIX=	yes
WRKSRC=			${WRKDIR}/Mesa-${PORTVERSION}
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes

INSTALL=		${LINUXBASE}/usr/bin/install

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	#
CONFIGURE_ARGS+=	--x-libraries="${LINUXBASE}/usr/X11R6/lib" \
			--x-includes="${LINUXBASE}/usr/X11R6/include" \
			--libdir="${PREFIX}/usr/X11R6/lib" \
			--includedir="${PREFIX}/usr/X11R6/include"
CONFIGURE_ENV=		PATH="${LINUXBASE}/bin:${LINUXBASE}/usr/bin:${PATH}" \
			GL_MAJOR_VER="${GL_MAJOR_VER}" \
			GL_MINOR_VER="${GL_MINOR_VER}" \
			GLUT_MAJOR_VER="${GLUT_MAJOR_VER}" \
			GLUT_MINOR_VER="${GLUT_MINOR_VER}"
GL_MAJOR_VER=		1
GL_MINOR_VER=		3
GLUT_MAJOR_VER=		3
GLUT_MINOR_VER=		8
LIBMESA_MAJOR_VER=	3

MAKE_ENV=		PATH=${LINUXBASE}/usr/bin:${PATH}
STRIP_CMD=		${LINUXBASE}/usr/bin/strip

PLIST_SUB+=		GL_MAJOR_VER=${GL_MAJOR_VER} \
			GL_MINOR_VER=${GL_MINOR_VER} \
			GLUT_MAJOR_VER=${GLUT_MAJOR_VER} \
			GLUT_MINOR_VER=${GLUT_MINOR_VER} \
			LIBMESA_MAJOR_VER=${LIBMESA_MAJOR_VER}

post-install:
	${STRIP_CMD} ${PREFIX}/usr/X11R6/lib/libglut.so.${GLUT_MAJOR_VER}.${GLUT_MINOR_VER}.0
	@for R in GL GLU; do \
		${STRIP_CMD} ${PREFIX}/usr/X11R6/lib/lib$$R.so.${GL_MAJOR_VER}.${GL_MINOR_VER}.0; \
		${LN} -s lib$$R.so ${PREFIX}/usr/X11R6/lib/libMesa$$R.so; \
		${LN} -s lib$$R.so.${GL_MAJOR_VER} ${PREFIX}/usr/X11R6/lib/libMesa$$R.so.${LIBMESA_MAJOR_VER}; \
	done
	${LINUXBASE}/sbin/ldconfig

.include <bsd.port.mk>
