# New ports collection makefile for:   bonobo-activation
# Date Created:			13 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonobo-activation
PORTVERSION=	2.2.4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An object activation framework for GNOME 2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_GNOME=	gnomehack libxml2 orbit2
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	bonobo-activation-server.1

.include <bsd.port.mk>
