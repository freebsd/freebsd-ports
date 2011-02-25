# New ports collection makefile for:	kchm
# Date created:				19 March 2005
# Whom:					pypt
#
# $FreeBSD$
#

PORTNAME=	kchm
PORTVERSION=	0.6.5
PORTREVISION=	11
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}new/${PORTNAME}new/${PORTNAME}-${PORTVERSION}

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	A KDE viewer for CHM files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

.include <bsd.port.mk>
