# Created by: Joel Sutton <jsutton@bbcon.com.au>
# $FreeBSD$

PORTNAME=	macutils
PORTVERSION=	2.0b3
CATEGORIES=	archivers emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress
DISTNAME=	${PORTNAME}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Utilities for Apple Macintosh files

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

BINDIR=		${STAGEDIR}${PREFIX}/bin
DOCFILES=	README.crc README.hexbin README.macput README.unpit \
		README.zoom README.crc.orig README.macget README.scan \
		README.unsit ../README

# The distribution has a naff install target which doesn't install man
# pages so here is a decent one.
#
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macunpack/macunpack ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/hexbin/hexbin ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/mixed/macsave ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/mixed/macstream ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/binhex/binhex ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/comm/tomac ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/comm/frommac ${BINDIR}/
	${INSTALL_MAN} ${WRKSRC}/man/macunpack.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hexbin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macsave.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macstream.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/binhex.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/tomac.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/frommac.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macutil.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
