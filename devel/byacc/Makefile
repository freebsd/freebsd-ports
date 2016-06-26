# $FreeBSD$

PORTNAME=	byacc
PORTVERSION=	20160606
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Best yacc variant available

GNU_CONFIGURE=	yes
MAKE_ARGS=	DEFINES="-DMAXTABLE=INT_MAX"
MAKEFILE=	makefile
TEST_TARGET=	check
USES=		tar:tgz

PLIST_FILES=	bin/yacc \
		man/man1/yacc.1.gz

.include <bsd.port.mk>
