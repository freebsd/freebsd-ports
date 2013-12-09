# Created by: trevor
# $FreeBSD$

PORTNAME=	showkey
PORTVERSION=	1.5
CATEGORIES=	converters
MASTER_SITES=	http://catb.org/~esr/showkey/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Prints its input, with escapes such as "<NUL>"

LICENSE=	MIT

USES=		gmake
MAKE_ARGS=	CC="${CC} ${CFLAGS}"
ALL_TARGET=	showkey

PLIST_FILES=	bin/showkey man/man1/showkey.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showkey ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/showkey.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
