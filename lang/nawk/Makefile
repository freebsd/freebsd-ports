PORTNAME=	nawk
DISTVERSION=	20260426
CATEGORIES=	lang

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Brian Kernighan's pattern scanning and processing language
WWW=		https://github.com/onetrueawk/awk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison gmake
USE_GITHUB=	yes
GH_ACCOUNT=	onetrueawk
GH_PROJECT=	awk

MAKEFILE=	makefile
ALL_TARGET=	a.out
TEST_TARGET=	test check
CFLAGS+=	-DHAS_ISBLANK
PLIST_FILES=	bin/nawk share/man/man1/nawk.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${STAGEDIR}${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/awk.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/nawk.1

.include <bsd.port.mk>
