# New ports collection makefile for:	gnetlist
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gnetlist
PORTVERSION=	20030223
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/
DISTNAME=	geda-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA electronic schematic capture tools, netlister

LIB_DEPENDS=	geda.18:${PORTSDIR}/cad/libgeda \
		guile.15:${PORTSDIR}/lang/guile
BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
AUTOCONF=	autoconf

USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gdgeda
INSTALLS_SHLIB=	yes

MAN1=		gnetlist.1

.include <bsd.port.mk>
