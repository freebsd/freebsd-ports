PORTNAME=	bigyear
PORTVERSION=	20010226
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://BSDforge.com/projects/source/deskutils/bigyear/
DISTNAME=	${PORTNAME}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Program to print a large (one month per page) calendar

LICENSE=	BSD0CLAUSE

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/bigyear share/man/man1/bigyear.1.gz

post-extract:
	@${RM} ${WRKSRC}/bigyear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bigyear ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bigyear.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
