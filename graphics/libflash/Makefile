# New ports collection makefile for:	FlashLib
# Date created:		10 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libflash
PORTVERSION=	0.4.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL Flash (TM) Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${DISTNAME}/lib

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ARGS=	NOPROFILE=true

.include <bsd.port.mk>
