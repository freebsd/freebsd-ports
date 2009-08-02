# New ports collection makefile for:	libkexiv2
# Date created:			14 March 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libkexiv2
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kipi

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A wrapper library to manipulate pictures metadata

LIB_DEPENDS=	exiv2.7:${PORTSDIR}/graphics/exiv2

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
