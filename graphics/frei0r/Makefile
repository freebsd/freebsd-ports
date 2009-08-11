# New ports collection makefile for:	frei0r
# Date created:		17 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frei0r
PORTVERSION=	1.1.22
PORTREVISION=	1
DISTVERSIONPREFIX=	plugins-
CATEGORIES=	graphics
MASTER_SITES=	http://propirate.net/${PORTNAME}/ \
		http://distfiles.macports.org/${PORTNAME}-plugins/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Minimalistic plugin API for video effects

LIB_DEPENDS=	cv.1:${PORTSDIR}/graphics/opencv \
		gavl.1:${PORTSDIR}/multimedia/gavl

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
