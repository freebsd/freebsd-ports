# New ports collection makefile for:   orbit2
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	ORBit2
PORTVERSION=	2.3.103
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-alpha2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		IDL-2.0:${PORTSDIR}/devel/libIDL \
		popt.0:${PORTSDIR}/devel/popt \
		linc.1:${PORTSDIR}/net/linc
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-indent
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${PREFIX}/etc/orbit2rc.default
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/orbit2rc.default
	@if [ ! -f ${PREFIX}/etc/orbit2rc ]; then \
		${CP} -p ${PREFIX}/etc/orbitrc.default ${PREFIX}/etc/orbit2rc ; \
	fi

.include <bsd.port.mk>
