# New ports collection makefile for:	grustibus
# Date created:		28 May 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	grustibus
PORTVERSION=	0.43
CATEGORIES=	emulators gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	grustibus

MAINTAINER=	verm@drunkmonk.net

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame
LIB_DEPENDS=	gnomecanvaspixbuf.1:${PORTSDIR}/graphics/gnomecanvas

USE_GNOMELIBS=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=`${GNOME_CONFIG} --sysconfdir`

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

.include <bsd.port.post.mk>
