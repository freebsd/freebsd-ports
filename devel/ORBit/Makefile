# New ports collection makefile for:   orbit
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	ORBit
PORTVERSION=	0.5.13
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/ORBit

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
USE_GLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-indent
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${TOUCH} ${WRKSRC}/configure

post-install:
	@${ECHO} "ORBIIOPIPv4=0" > ${PREFIX}/etc/orbitrc.default
	@${ECHO} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/orbitrc.default
	@if [ ! -f ${PREFIX}/etc/orbitrc ]; then \
		${CP} -p ${PREFIX}/etc/orbitrc.default ${PREFIX}/etc/orbitrc ; \
	fi
.for dir in IIOP ORBitservices ORBitutil orb orbit-idl2.h
	@if [ -L ${PREFIX}/include/${dir} ]; then \
		${RM} -f ${PREFIX}/include/${dir}; \
	fi
	@${LN} -sf ${PREFIX}/include/orbit-1.0/${dir} ${PREFIX}/include/${dir}
.endfor
	@if [ -L ${PREFIX}/include/libIDL ]; then \
		${RM} -f ${PREFIX}/include/libIDL; \
	fi
	@${LN} -sf ${PREFIX}/include/libIDL-1.0/libIDL ${PREFIX}/include/libIDL

.include <bsd.port.mk>
