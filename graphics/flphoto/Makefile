# New ports collection makefile for:   	flPhoto
# Date created:				24 November, 2003
# Whom:                			johan
#
# $FreeBSD$
#

PORTNAME=	flphoto
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fltk
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic image management and display program

LIB_DEPENDS=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		flphoto.1
MAN5=		album.5

.include <bsd.port.mk>
