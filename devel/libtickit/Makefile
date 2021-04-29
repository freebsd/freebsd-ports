# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	libtickit
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libtickit/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal Interface Construction Kit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtermkey.so:devel/libtermkey

USES=		gmake libtool:build ncurses pathfix pkgconfig

MAKE_ARGS=	MANDIR=${PREFIX}/share/man
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes

.include <bsd.port.mk>
