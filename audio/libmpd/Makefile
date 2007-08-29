# New ports collection makefile for:	libmpd
# Date created:		Apr 4 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmpd
PORTVERSION=	0.14.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/gmpc-0.15.0/ \
				http://download.gna.org/kanicule/freebsd/distfiles/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Abstraction around libmpdclient

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
