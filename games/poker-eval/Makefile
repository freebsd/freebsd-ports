# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-eval
PORTVERSION=	0.138
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to evaluate poker hands

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
