# New ports collection makefile for:	mixmos
# Date created:		24 Jul 2004
# Whom:			Herbert J. Skuhra <herbert.skuhra@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	mixmos
PORTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	herbert.skuhra@gmx.at
COMMENT=	A GTK2 audio mixer

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mixmos.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501105
IGNORE=		require SOUND_MIXER_INFO ioctl
.endif

.include <bsd.port.post.mk>
