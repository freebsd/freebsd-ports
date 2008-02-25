# New ports collection makefile for:	gnomebuild
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gnome-build/Makefile,v 1.5 2007/09/09 22:45:25 mezz Exp $
#

PORTNAME=	gnome-build
PORTVERSION=	0.2.3
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Build Framework (GBF)

LIB_DEPENDS=	gdl-gnome-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui gnomevfs2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.mk>
