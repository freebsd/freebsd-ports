# New ports collection makefile for:   glib12
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	1.2.10
CATEGORIES=	devel
#MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
#		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
#		http://www.ameth.org/gimp/%SUBDIR%/ \
#		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITES=	${MASTER_SITE_GNOME}
#MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
MASTER_SITE_SUBDIR=	stable/sources/glib

MAINTAINER=	ade@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib12
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		glib12-config.1

.include <bsd.port.mk>
