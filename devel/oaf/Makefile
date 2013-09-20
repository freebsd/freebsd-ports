# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/oaf/Makefile,v 1.5 2007/05/19 21:36:06 marcus Exp $

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

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gtk12 orbit libxml
USES=		gettext gmake perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS= --enable-static --enable-shared \
		--disable-more-warnings
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=	oafd.1

NO_STAGE=	yes
.include <bsd.port.mk>
