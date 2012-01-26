# New ports collection makefile for:	pinpoint
# Date created:        26 June 2011
# Whom:                lichray@gmail.com
#
# $FreeBSD$
#

PORTNAME=	pinpoint
DISTVERSION=	0.1.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	lichray@gmail.com
COMMENT=	A tool for making hackers do excellent presentations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack librsvg2
GNU_CONFIGURE=	yes

OPTIONS=	GST "Enable live videos as slide backgrounds" off

.include <bsd.port.options.mk>

.if defined(WITH_GST)
LIB_DEPENDS+=	clutter-gst-1.0:${PORTSDIR}/multimedia/clutter-gst
.else
CONFIGURE_ARGS+=	--enable-cluttergst=no
.endif

.include <bsd.port.mk>
