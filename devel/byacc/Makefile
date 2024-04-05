PORTNAME=	byacc
PORTVERSION=	20240109
CATEGORIES=	devel
MASTER_SITES=	https://invisible-island.net/archives/byacc/ \
		https://invisible-mirror.net/archives/byacc/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Best yacc variant available
WWW=		https://invisible-island.net/byacc/

LICENSE=	PD

USES=		tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_ARGS=	DEFINES="-DMAXTABLE=INT_MAX"
MAKEFILE=	makefile
TEST_TARGET=	check

PLIST_FILES=	bin/yacc \
		share/man/man1/yacc.1.gz

.include <bsd.port.mk>
