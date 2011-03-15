# New ports collection makefile for:	xmms-infinity
# Date created:				14 Dec 2001
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-infinity
PORTVERSION=	0.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://julien.carme.free.fr/
DISTNAME=	infinity-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XMMS plug-in which generate full-screen interactive light effects

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libinfinite.so lib/xmms/Visualization/libinfinite.la \
		lib/xmms/Visualization/libinfinite.a share/xmms/infinite_states
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
