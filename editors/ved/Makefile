# New ports collection makefile for:   ved
# Date created:        31 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ved
PORTVERSION=	1.5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/ved/

MAINTAINER=	greid@ukug.uk.freebsd.org

USE_GMAKE=	yes

MAN1=		ved.1

post-patch:
.for F in ved.h ved.1
	${SED} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/ved/$F \
		> ${WRKSRC}/ved/foo
	${MV} ${WRKSRC}/ved/foo ${WRKSRC}/ved/$F
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ved/OBJ/${ARCH}-freebsd-cc/ved \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ved/ved.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/ved/ved.help ${PREFIX}/share

.include <bsd.port.mk>
