# New ports collection makefile for:   orbit
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	ORBit
PORTVERSION=	0.5.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/ORBit

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_GLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure libIDL/configure popt/configure
CONFIGURE_ARGS= --disable-indent
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	@${ECHO} "ORBIIOPIPv4=0" > ${PREFIX}/etc/orbitrc.default
	@${ECHO} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/orbitrc.default
	@if [ ! -f ${PREFIX}/etc/orbitrc ]; then \
		${CP} -p ${PREFIX}/etc/orbitrc.default ${PREFIX}/etc/orbitrc ; \
	fi

.include <bsd.port.mk>
