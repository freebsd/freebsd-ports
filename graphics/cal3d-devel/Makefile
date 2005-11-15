# New ports collection makefile for:	cal3d
# Date created:				12 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	cal3d
DISTVERSION=	${CAL3DVER}_pre20050823
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Skeletal based 3d character animation library written in C++ (devel)

CAL3DVER=	0.11.0

CONFLICTS=	cal3d-[0-9]*

USE_BZIP2=		yes
USE_GNOME=		pkgconfig
USE_GCC=		3.2+
USE_AUTOTOOLS=	automake:19 autoheader:259 libtool:15:inc
AUTOMAKE_ARGS=		"--add-missing"
INSTALLS_SHLIB=		yes
CPPFLAGS+=		-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-static
MAKE_ARGS=		CC="${CC}" CFLAGS="${CFLAGS} ${CXX}"
WRKSRC=			${WRKDIR}/${PORTNAME}

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${LIBTOOLIZE} --automake --force

.include <bsd.port.mk>
