# New ports collection makefile for:	oaf
# Date created:				1st June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/oaf/Makefile,v 1.5 2007/05/19 21:36:06 marcus Exp $
#

PORTNAME=	oaf
PORTVERSION=	0.6.10
PORTREVISION=	9
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/oaf/0.6
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object Activation Framework for GNOME

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk12 orbit libxml
USE_GETTEXT=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS= --enable-static --enable-shared \
		--disable-more-warnings
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=	oafd.1

.include <bsd.port.mk>
