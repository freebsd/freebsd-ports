# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	gsymcheck
PORTVERSION=	20020825
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/20020825/ \
		http://geda.seul.org/devel/20020825/ \
		http://www.tinkerbox.org/projects/files/gEDA/
DISTNAME=	geda-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bruno@tinkerbox.org

BUILD_DEPENDS=	gesym-config:${PORTSDIR}/cad/geda-symbols
LIB_DEPENDS=	geda.16:${PORTSDIR}/cad/libgeda \
		guile.10:${PORTSDIR}/lang/guile

USE_LIBTOOL=	yes
#USE_AUTOCONF=	yes
AUTOCONF=	autoconf
USE_GNOMENG=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gdgeda
INSTALLS_SHLIB=	yes

MAN1=		gsymcheck.1

.include <bsd.port.mk>
