# New ports collection makefile for:   macutils
# Version required:	2.0b3
# Date created:		14th April 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
# FreeBSD Version:	2.1.5-RELEASE
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 03:46:57 asami Exp $
#
      
DISTNAME=	macutils_2.0b3.orig
PKGNAME=	macutils-2.0b3
CATEGORIES=	emulators
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/distributions/debian/bo/source/otherosfs/
# ${MASTER_SITE_SUNSITE} isn't appropriate because distributions/ isn't
# mirrored.

MAINTAINER=	sutton@aardvark.apana.org.au

WRKSRC=		${WRKDIR}/macutils-2.0b3.orig
MAKEFILE=	makefile

MANDIR=		${PREFIX}/man/man
BINDIR=		${PREFIX}/bin
DOCDIR=		${PREFIX}/share/doc/macutils
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
	${INSTALL_MAN} ${WRKSRC}/man/macunpack.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/hexbin.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/macsave.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/macstream.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/binhex.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/tomac.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/frommac.1 ${MANDIR}1/
	${INSTALL_MAN} ${WRKSRC}/man/macutil.1 ${MANDIR}1/
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing supplementary documents..."
	-${MKDIR} ${DOCDIR}/
	for file in ${DOCFILES} ; do \
	  ${INSTALL_DATA} ${WRKSRC}/doc/$$file ${DOCDIR}/ ;\
	done
.endif

.include <bsd.port.mk>

