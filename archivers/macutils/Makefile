# New ports collection makefile for:	macutils
# Date created:		14th April 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	macutils
PORTVERSION=	2.0b3
CATEGORIES=	archivers emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for Apple Macintosh files

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

MAN1=		macunpack.1 hexbin.1 macsave.1 macstream.1 binhex.1 tomac.1 \
		frommac.1 macutil.1

BINDIR=		${PREFIX}/bin
DOCFILES=	README.crc README.hexbin README.macput README.unpit \
		README.zoom README.crc.orig README.macget README.scan \
		README.unsit ../README

# The distribution has a naff install target which doesn't install man
# pages so here is a decent one.
#
do-install:
	@${ECHO_MSG} "===>  Installing binaries..."
	${INSTALL_PROGRAM} ${WRKSRC}/macunpack/macunpack ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/hexbin/hexbin ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/mixed/macsave ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/mixed/macstream ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/binhex/binhex ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/comm/tomac ${BINDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/comm/frommac ${BINDIR}/
	@${ECHO_MSG} "===>  Installing man pages..."
	${INSTALL_MAN} ${WRKSRC}/man/macunpack.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hexbin.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macsave.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macstream.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/binhex.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/tomac.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/frommac.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/macutil.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing supplementary documents..."
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
