# New ports collection makefile for: otcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	otcl
PORTVERSION=	1.0a8
CATEGORIES=	lang tcl83 tk83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	otcl-tclcl

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--with-tcl-ver=8.3 --with-tk-ver=8.3
INSTALLS_SHLIB=	yes

PKGINSTALL=	${PORTSDIR}/lang/tcl83/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl83/pkg-deinstall.tclsh

post-install:
	${LN} -sf libotcl.so ${PREFIX}/lib/libotcl.so.1
	${STRIP_CMD} ${PREFIX}/bin/otclsh
	${STRIP_CMD} ${PREFIX}/bin/owish
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.mk>
