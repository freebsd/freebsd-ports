# New ports collection makefile for: libdssialsacompat
# Date created: 14 July 2006
# Whom:	mahonmesr@googlemail.com
#
# $FreeBSD$
#

PORTNAME=	libdssialsacompat
PORTVERSION=	1.0.8a
CATEGORIES=	audio
MASTER_SITES=	http://www.smbolton.com/linux/

MAINTAINER=	freebsd-ports@coreland.ath.cx
COMMENT=	Alsa compatibility library to build DSSI

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
