# New ports collection makefile for:	lash
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	lash
PORTVERSION=	0.5.4
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session management system for JACK audio applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat

USE_GNOME=	gnomehack gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa-midi
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
