# New ports collection makefile for:	gedit-plugins
# Date created:				19 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gedit-plugins
PORTVERSION=	2.3.5
PORTREVISION=	3
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for gedit2

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget lthack
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
