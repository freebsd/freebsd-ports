# $FreeBSD$

PORTNAME=	byacc
PORTVERSION=	20150711
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Best yacc variant available

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/yacc \
		man/man1/yacc.1.gz

regression-test: build
	@cd ${WRKSRC}; ${MAKE_CMD} check

.include <bsd.port.mk>
