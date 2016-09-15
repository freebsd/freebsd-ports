# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-eval
PORTVERSION=	138.0
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library to evaluate poker hands

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
