PORTNAME=	bigyear
PORTVERSION=	20010226
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	https://BSDforge.com/projects/source/deskutils/bigyear/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to print a large (one month per page) calendar

BROKEN=		Unfetchable
DEPRECATED=	Last release in 2001 and dead upstream, consider using deskutils/pal
EXPIRATION_DATE=2024-02-29

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/bigyear man/man1/bigyear.1.gz

post-extract:
	@${RM} ${WRKSRC}/bigyear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bigyear ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bigyear.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
