# New ports collection makefile for: pdcurses
# Version required:	2.2
# Date created:		Sun Jun 22 16:57:39 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au)
# FreeBSD Version:	2.2.1-RELEASE
#
# $Id: Makefile,v 1.3 1998/11/07 07:42:12 asami Exp $
#

DISTNAME=	pdc22
PKGNAME=	crossgo32-djgpp2-pdcurses-2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.tas.gov.au/pc/simtelnet/gnu/djgpp/v2tk/ \
		ftp://ftp.cdrom.com/pub/simtelnet/gnu/djgpp/v2tk/
EXTRACT_SUFX=	.zip

MAINTAINER=	sutton@aardvark.apana.org.au

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	i386-go32-gcc:${PORTSDIR}/devel/crossgo32
RUN_DEPENDS=	i386-go32-stubify:${PORTSDIR}/devel/crossgo32-djgpp2

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-La
EXTRACT_AFTER_ARGS=	# empty

# Since were only taking the library and include files we don't
# actually need to build anything
#
WRKSRC=		${WRKDIR}/contrib/pdcurs22
NO_BUILD=	yes

CROSSGOLIB=	${PREFIX}/i386-go32/lib
CROSSGOINCLUDE=	${PREFIX}/i386-go32/include
PDBASE=		${WRKSRC}/contrib/pdcurs22
PDLIB=		${WRKSRC}/lib
PDINCLUDE=	${WRKSRC}/include
PDDOC=		${WRKSRC}/docs
DOCDIR=		${PREFIX}/share/doc/pdcurses

do-install:
	@${ECHO_MSG} "===>  Installing libraries"
	${INSTALL_DATA} ${PDLIB}/libcurso.a ${CROSSGOLIB}
	${INSTALL_DATA} ${PDLIB}/libcurso.a ${CROSSGOLIB}/libcurses.a
	${INSTALL_DATA} ${PDLIB}/libpano.a ${CROSSGOLIB}

	@${ECHO_MSG} "===>  Installing include files"
	${INSTALL_DATA} ${PDINCLUDE}/curses.h ${CROSSGOINCLUDE}
	${INSTALL_DATA} ${PDINCLUDE}/cursos2.h ${CROSSGOINCLUDE}
	${INSTALL_DATA} ${PDINCLUDE}/curspriv.h ${CROSSGOINCLUDE}
	${INSTALL_DATA} ${PDINCLUDE}/panel.h ${CROSSGOINCLUDE}

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documentation into ${DOCDIR}"
	-${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${PDDOC}/readme.22 ${DOCDIR}/readme.txt
	${INSTALL_DATA} ${PDDOC}/basics/intro.man ${DOCDIR}/intro.txt
	${INSTALL_DATA} ${PDDOC}/basics/overview.man ${DOCDIR}/overview.txt
	${INSTALL_DATA} ${PDDOC}/basics/xwindows.man ${DOCDIR}/xwindows.txt
	${INSTALL_DATA} ${PKGDIR}/DESCR ${DOCDIR}/Readme.FreeBSD
.endif

.include <bsd.port.mk>
