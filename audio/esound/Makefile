# New ports collection makefile for:	esound
# Date created:		19 July 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/esound

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
