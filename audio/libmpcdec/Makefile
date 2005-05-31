# New ports collection makefile for:   libmusepack
# Date created:        29 November 2004
# Whom:                Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpcdec
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.saunalahti.fi/grimmel/musepack.net-files/source/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	High quality audio compression format

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O3\ -fomit-frame-pointer||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
