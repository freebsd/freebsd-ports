# New ports collection makefile for:   libbonobo
# Date Created:			14 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libbonobo
PORTVERSION=	2.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A component and compound document system for GNOME2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_PERL5=	yes
USE_GNOME=	gnomehack intlhack libxml2 orbit2
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ENV=	gnomelocaledir=${PREFIX}/share/locale

MAN1=		bonobo-activation-server.1

.include <bsd.port.mk>
