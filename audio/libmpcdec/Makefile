# New ports collection makefile for:   libmpcdec
# Date created:        29 November 2004
# Whom:                Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpcdec
PORTVERSION=	1.2.5
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	High quality audio compression format

USE_BZIP2=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O3\ -fomit-frame-pointer||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
