# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	3.1.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and mp3 encoders

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl.2:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui vte
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdpar
.endif

.include <bsd.port.mk>
