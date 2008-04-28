# New ports collection makefile for:   libconfig
# Date created:                September 26, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	libconfig
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.hyperrealm.com/libconfig/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A simple library for manipulating structured configuration files

USE_GNOME=	gnomehack pkgconfig
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${INFO_PATH}
INFO=		libconfig

.include <bsd.port.mk>
