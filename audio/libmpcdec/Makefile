# New ports collection makefile for:   libmpcdec
# Date created:        29 November 2004
# Whom:                Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpcdec
PORTVERSION=	1.2.2
CATEGORIES=	audio
MASTER_SITES=	http://files2.musepack.net/source/ \
		http://www.saunalahti.fi/grimmel/musepack.net-files/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality audio compression format

USE_BZIP2=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O3\ -fomit-frame-pointer||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
