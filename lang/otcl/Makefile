# New ports collection makefile for: otcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	otcl
PORTVERSION=	1.0a7
CATEGORIES=	lang tcl83 tk83
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	MIT Object Tcl

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.3 --with-tk-ver=8.3
USE_AUTOCONF=	yes
PKGINSTALL=	${PORTSDIR}/lang/tcl83/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl83/pkg-deinstall.tclsh

post-install:
	${LN} -sf libotcl.so ${PREFIX}/lib/libotcl.so.1
	strip ${PREFIX}/bin/otclsh
	strip ${PREFIX}/bin/owish
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.mk>
