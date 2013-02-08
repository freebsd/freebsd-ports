# New ports collection makefile for:	gpredict
# Date created:		2004-01-22
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/gpredict/Gpredict/${PORTVERSION}

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio satellite tracking and prediction

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		goocanvas:${PORTSDIR}/graphics/goocanvas
BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --localedir=${PREFIX}/share/locale
USE_GMAKE=	yes

MAN1=		gpredict.1

LICENSE=	GPLv2

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

DESKTOP_ENTRIES="GPREDICT" \
		"Predict satellite passage times" \
		"${PREFIX}/share/pixmaps/gpredict/icons/gpredict-icon.png" \
		"gpredict" \
		"" \
		true

.include <bsd.port.mk>
