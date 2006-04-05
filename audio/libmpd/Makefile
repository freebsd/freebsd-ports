# New ports collection makefile for:	libmpd
# Date created:		Apr 4 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmpd
PORTVERSION=	0.12.0
CATEGORIES=	audio
MASTER_SITES=	http://download.qballcow.nl/programs/gmpc-0.13/

MAINTAINER=	redchrom@gmail.com
COMMENT=	Abstraction around libmpdclient

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
