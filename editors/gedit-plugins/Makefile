# New ports collection makefile for:	gedit-plugins
# Date created:				19 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gedit-plugins
PORTVERSION=	2.3.5
PORTREVISION=	6
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for gedit

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|gedit-2.4|gedit-2.10|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
