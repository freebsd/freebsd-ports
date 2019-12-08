# $FreeBSD$

PORTNAME=	byacc
PORTVERSION=	20191125
CATEGORIES=	devel
MASTER_SITES=	https://invisible-mirror.net/archives/byacc/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Best yacc variant available

LICENSE=	PD

USES=		tar:tgz

GNU_CONFIGURE=	yes
MAKE_ARGS=	DEFINES="-DMAXTABLE=INT_MAX"
MAKEFILE=	makefile
TEST_TARGET=	check

PLIST_FILES=	bin/yacc \
		man/man1/yacc.1.gz

.include <bsd.port.mk>
