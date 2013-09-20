# Created by: mahonmesr@googlemail.com
# $FreeBSD$

PORTNAME=	libdssialsacompat
PORTVERSION=	1.0.8a
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alsa compatibility library to build DSSI

FETCH_ARGS?=	-Fpr
USE_AUTOTOOLS=	libtool
NO_STAGE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
