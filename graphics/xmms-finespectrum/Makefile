# New ports collection makefile for:	xmms-finespectrum
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-finespectrum
PORTVERSION=	1.0.1.a
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	finespectrum
DISTNAME=	finespectrum-1.0.1alpha

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Fine grain Spectrum analyzers for XMMS

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libfinespectrum.so
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/finespectrum-1.0.1alpha

.include <bsd.port.mk>
