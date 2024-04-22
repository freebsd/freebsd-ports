PORTNAME=	intercal
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	C-INTERCAL compiler, ick, and supporting libraries
WWW=		https://gitlab.com/esr/intercal

LICENSE=	GPLv2

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CPPFLAGS+=	-DCC='\"${CC}\"'
DATADIR=	${PREFIX}/share/ick

INFO=		ick
TEST_TARGET=	check

.include <bsd.port.mk>
