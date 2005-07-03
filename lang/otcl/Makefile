# New ports collection makefile for: otcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	otcl
PORTVERSION=	1.9
CATEGORIES=	lang tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	otcl-tclcl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIT Object Tcl

LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84

USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4
INSTALLS_SHLIB=	yes

PKGINSTALL=	${PORTSDIR}/lang/tcl84/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl84/pkg-deinstall.tclsh

post-install:
	${LN} -sf libotcl.so ${PREFIX}/lib/libotcl.so.1
	${STRIP_CMD} ${PREFIX}/bin/otclsh
	${STRIP_CMD} ${PREFIX}/bin/owish
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.mk>
