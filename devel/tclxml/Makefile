# New ports collection makefile for:	tclxml
# Date created:				2 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	tclxml
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tclxml

MAINTAINER=	dyeske@yahoo.com
COMMENT=	API for parsing XML documents using Tcl

BUILD_DEPENDS=	tclsh8.4:${PORTSDIR}/lang/tcl84
RUN_DEPENDS=	tclsh8.4:${PORTSDIR}/lang/tcl84 \
		${LOCALBASE}/lib/tcllib1.7/uri/uri.tcl:${PORTSDIR}/devel/tcllib

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
		--with-tclinclude=${LOCALBASE}/include/tcl8.4
PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
