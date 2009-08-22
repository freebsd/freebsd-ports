# New ports collection makefile for:	libkdcraw
# Date created:			22 June 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libkdcraw
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/kipi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A C++ interface around the LibRaw library

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
