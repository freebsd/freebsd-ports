# New ports collection makefile for:   libbonobo
# Date Created:			14 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/libbonobo/Makefile,v 1.45 2006/04/13 07:52:33 bland Exp $
#

PORTNAME=	libbonobo
PORTVERSION=	2.14.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A component and compound document system for GNOME2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_GETTEXT=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack intlhack libxml2 orbit2
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ENV=	gnomelocaledir=${PREFIX}/share/locale

MAN1=		bonobo-activation-server.1

.include <bsd.port.mk>
