# New ports collection makefile for:	grustibus
# Date created:		28 May 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	grustibus
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	emulators gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	grustibus

MAINTAINER=	verm@drunkmonk.net
COMMENT=	An xmame frontend for Gnome

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gnomecanvas
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=`${GNOME_CONFIG} --sysconfdir`

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs libcapplet
.endif

.include <bsd.port.post.mk>
