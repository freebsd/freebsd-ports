# New ports collection makefile for:	esound
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.35
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A sound library for enlightenment package

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_GETOPT_LONG=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnometarget gnomehack
USE_LIBTOOL_VER=15

CONFLICTS=	py*-ro-*

MAN1=	esd-config.1 esd.1 esdcat.1 esdctl.1 esddsp.1 esdfilt.1 esdloop.1 \
	esdmon.1 esdplay.1 esdrec.1 esdsample.1

.include <bsd.port.mk>
