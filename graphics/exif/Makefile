# New ports collection makefile for:	exif
# Date created:				May 02 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exif
PORTVERSION=	0.6.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libexif

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Command line utility to read and manipulate EXIF data

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		popt.0:${PORTSDIR}/devel/popt

USE_LIBTOOL_VER=15

MAN1=		exif.1

.include <bsd.port.mk>
