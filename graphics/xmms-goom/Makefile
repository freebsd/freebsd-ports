# New ports collection makefile for:	xmms-goom
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	goom
PORTVERSION=	1.7.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	goom
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-goom_${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes

pre-patch:
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG}|g;' \
		${WRKSRC}/configure
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG}|g; s|-lgtk|-lgtk12|g;' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
