# New ports collection makefile for:	Mesa3 for Linux compat
# Date created:		May 18 2000
# Whom:			Masahiro TAKEMURA
#
# $FreeBSD$
#

PORTNAME=		mesa
PORTVERSION=		3.4.2
CATEGORIES=		graphics linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			ftp://iris.ssec.wisc.edu/pub/Mesa/ \
			ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
PKGNAMEPREFIX=		linux_
DISTFILES=		MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
			MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		mastake@msel.t.u-tokyo.ac.jp

BUILD_DEPENDS=	${PREFIX}/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base \
		${PREFIX}/usr/bin/gcc:${PORTSDIR}/devel/linux_devtools
RUN_DEPENDS=	${PREFIX}/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

USE_BZIP2=		yes
ONLY_FOR_ARCHS=		i386
PREFIX=			/compat/linux
WRKSRC=			${WRKDIR}/Mesa-${PORTVERSION}
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes

INSTALL=		${PREFIX}/usr/bin/install

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	#
CONFIGURE_ARGS=		--libdir="${PREFIX}/usr/X11R6/lib" \
			--includedir="${PREFIX}/usr/X11R6/include"
CONFIGURE_ENV=		PATH="/compat/linux/bin:/compat/linux/usr/bin:${PATH}"\
			GL_MAJOR_VER="${GL_MAJOR_VER}" \
			GL_MINOR_VER="${GL_MINOR_VER}" \
			GLUT_MAJOR_VER="${GLUT_MAJOR_VER}" \
			GLUT_MINOR_VER="${GLUT_MINOR_VER}"
GL_MAJOR_VER=		1
GL_MINOR_VER=		3
GLUT_MAJOR_VER=		3
GLUT_MINOR_VER=		8

MAKE_ENV=		PATH=${PREFIX}/usr/bin:${PATH}

.include <bsd.port.pre.mk>

post-install:
	${PREFIX}/sbin/ldconfig

.include <bsd.port.post.mk>
