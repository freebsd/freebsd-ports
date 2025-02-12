PORTNAME=	intercal
PORTVERSION=	0.33
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries
WWW=		https://gitlab.com/esr/intercal

LICENSE=	GPLv2

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DCC='\"${CC}\"'
DATADIR=	${PREFIX}/share/ick

INFO=		ick
TEST_TARGET=	check

.include <bsd.port.mk>
