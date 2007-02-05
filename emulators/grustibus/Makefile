# New ports collection makefile for:	grustibus
# Date created:		28 May 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	grustibus
PORTVERSION=	0.43
PORTREVISION=	4
CATEGORIES=	emulators gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xmame frontend for Gnome

DEPRECATED=	Project was abandoned 6 years ago and expects an old version of xmame (0.37b4), please use other frontends instead (like gxmame)
EXPIRATION_DATE=2007-03-07

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_X_PREFIX=	yes
USE_GNOME=	gnomecanvas gnomehack gnomeprefix libcapplet
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--sysconfdir=`${GNOME_CONFIG} --sysconfdir`

.include <bsd.port.mk>
