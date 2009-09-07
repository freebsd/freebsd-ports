# ex:ts=8
# Ports collection Makefile for:	poker-eval
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	poker-eval
PORTVERSION=	0.136
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library to evaluate poker hands

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MD5SUM=${MD5}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
