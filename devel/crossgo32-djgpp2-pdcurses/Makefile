# New ports collection makefile for:	pdcurses
# Date created:		Sun Jun 22 16:57:39 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au)
#
# $FreeBSD$
#

PORTNAME=	crossgo32-djgpp2-pdcurses
PORTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ntu.edu.tw/UNIX/GNU/djgpp/v2tk/ \
		ftp://ftp.in-span.net/disk/disk5/simtel.net/gnu/djgpp/v2tk/ \
		ftp://ftp.informatik.uni-hamburg.de/ftpmnt/rrz1/pub/os/dos/djgpp/v2tk/ \
		ftp://ftp.uni-koeln.de/pc/djgpp/v2tk/
DISTNAME=	pdc22

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PD curses for crossgo32 crosscompiler with djgpp v2 libraries

RUN_DEPENDS=	i386-go32-stubify:${PORTSDIR}/devel/crossgo32-djgpp2

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qLa

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
	${INSTALL_DATA} ${DESCR} ${DOCDIR}/README.FreeBSD
.endif

.include <bsd.port.mk>
