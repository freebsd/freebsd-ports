# New ports collection makefile for:   orbit
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	ORBit
PORTVERSION=	0.5.17
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/ORBit/0.5
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High-performance CORBA ORB with support for the C language

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12 gnometarget
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure popt/configure libIDL/configure
CONFIGURE_ARGS= --disable-indent
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		libIDL

CONFLICTS=	ORBacus-*

post-patch:
	@${TOUCH} ${WRKSRC}/configure

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${PREFIX}/etc/orbitrc.default
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/orbitrc.default
	@if [ ! -f ${PREFIX}/etc/orbitrc ]; then \
		${CP} -p ${PREFIX}/etc/orbitrc.default ${PREFIX}/etc/orbitrc ; \
	fi

.include <bsd.port.mk>
