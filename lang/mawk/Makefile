PORTNAME=	mawk
DISTVERSION=	1.3.4-20240622
CATEGORIES=	lang
MASTER_SITES=	https://invisible-island.net/archives/mawk/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Interpreter for the AWK Programming Language
WWW=		https://invisible-island.net/mawk/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		tar:tgz

PLIST_FILES=	bin/mawk \
		share/man/man1/mawk.1.gz \
		share/man/man7/mawk-arrays.7.gz \
		share/man/man7/mawk-code.7.gz

.include <bsd.port.mk>
