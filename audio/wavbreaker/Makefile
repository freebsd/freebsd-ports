# New ports collection makefile for:	wavbreaker
# Date created:				20 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to split wav files

USE_GNOME=	gnomehack gnometarget gtk20 libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-alsa
INSTALLS_ICONS=	yes

MAN1=		wavbreaker.1 wavinfo.1 wavmerge.1

.include <bsd.port.mk>
