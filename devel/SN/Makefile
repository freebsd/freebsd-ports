# New ports collection makefile for:	SN
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	SN
PORTVERSION=	4.5.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.unina.it/pub/Unix/cygnus/%SUBDIR% \
	ftp://unix.hensa.ac.uk/mirrors/sourceware.cygnus.com/pub/%SUBDIR% \
	ftp://ftp.funet.fi/pub/mirrors/sourceware.cygnus.com/pub/%SUBDIR% \
	ftp://gd.tuwien.ac.at/gnu/sourceware/%SUBDIR% \
	ftp://ftp.pvv.ntnu.no/pub/cygnus/sourceware.cygnus.com/%SUBDIR% \
	ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR% \
	ftp://sources.redhat.com/pub/%SUBDIR% \
	ftp://sourceware.cygnus.com/pub/%SUBDIR% \
	ftp://ftp.sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/%SUBDIR% \
	ftp://ftp.ai-lab.fh-furtwangen.de/pub/mirror/sources.redhat.com/pub/%SUBDIR% \
	ftp://ftp.sun.ac.za/sites/sourceware.cygnus.com/pub/%SUBDIR%
MASTER_SITE_SUBDIR=	sourcenav/releases/
DISTNAME=	SN452

MAINTAINER=	dburr@FreeBSD.ORG

BROKEN=		"Does not build"

PREFIX=		${LOCALBASE}/SN
GNU_CONFIGURE=	yes
MAKEINSTALL=	${SETENV} ${MAKE_ENV} ${GMAKE} install
NO_MTREE=	yes
SNSRC=	${WRKDIR}/compile/snavigator
SNSRC2=	${WRKDIR}/SN452-source
SNSRC3=	${SNSRC2}/snavigator
USE_XLIB=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/compile

do-configure:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC}; \
	${SNSRC2}/configure --prefix=${PREFIX} ${CONFIGURE_TARGET}

do-install:
.for i in bin lib
	${MKDIR} ${PREFIX}/${i}
.endfor
.for i in bitmaps libgui/library cygnus/gui sdk/api/tcl/misc itcl1.5 \
	tix4.1/library/bitmaps tix4.1/library/pref
		${MKDIR} ${PREFIX}/share/${i}
.endfor
.if !defined(NOPORTDOCS)
.for i in sdk/api/c/database/examples \
	sdk/api/tcl/database/examples \
	html/edk/userguide \
	html/enterprise/userguide
		${MKDIR} ${PREFIX}/share/doc/${i}
.endfor
.endif
.for i in \
	db/dbcp \
	db/dbdump \
	db/dbimp \
	hyper/hyper \
	parsers/assembly/ppc601-eabi/abrowser \
	parsers/cobol/obrowser \
	parsers/cpp/cbrowser \
	parsers/fortran/fbrowser \
	parsers/java/jbrowser \
	parsers/tcl/tbrowser
		${INSTALL_PROGRAM} ${SNSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} \
		${SNSRC3}/snavigator/unix/elix-link \
		${PREFIX}/bin
	${INSTALL_DATA} ${SNSRC}/misc/libutils/libutils.a \
		${PREFIX}/lib/
	${INSTALL_DATA} ${SNSRC3}/bitmaps/*.xpm \
		${PREFIX}/share/bitmaps/
	${INSTALL_DATA} ${SNSRC2}/libgui/library/tclIndex \
		${SNSRC2}/libgui/library/*.tcl \
		${PREFIX}/share/libgui/library/
	${INSTALL_DATA} ${SNSRC2}/itcl/library/tclIndex \
		${SNSRC2}/itcl/library/*.tcl \
		${PREFIX}/share/itcl1.5/
	${INSTALL_DATA} ${SNSRC2}/tix/library/tclIndex \
		${SNSRC2}/tix/library/*.tcl \
		${PREFIX}/share/tix4.1/
	${INSTALL_DATA} ${SNSRC2}/tix/library/bitmaps/* \
		${PREFIX}/share/tix4.1/library/bitmaps
	${INSTALL_DATA} ${SNSRC2}/tix/library/pref/* \
		${PREFIX}/share/tix4.1/library/pref
	${INSTALL_DATA} ${SNSRC3}/gui/tclIndex \
		${SNSRC3}/gui/*.tcl \
		${PREFIX}/share/cygnus/gui/
.if !defined(NOPORTDOCS)
.for i in README COPYING COPYING.LIB
	${INSTALL_DATA} ${SNSRC2}/${i} ${PREFIX}/share/doc/
.endfor
	${INSTALL_DATA} ${SNSRC3}/sdk/api/c/database/examples/* \
		${PREFIX}/share/doc/sdk/api/c/database/examples/
	${INSTALL_DATA} ${SNSRC3}/sdk/api/tcl/database/examples/* \
		${PREFIX}/share/doc/sdk/api/tcl/database/examples/
	${INSTALL_DATA} ${SNSRC3}/doc/html/edk/userguide/* \
		${PREFIX}/share/doc/html/edk/userguide/
	${INSTALL_DATA} ${SNSRC3}/doc/html/enterprise/userguide/* \
		${PREFIX}/share/doc/html/enterprise/userguide/
.endif
	${INSTALL_DATA} ${SNSRC3}/sdk/api/tcl/misc/* \
		${PREFIX}/share/sdk/api/tcl/misc/
.for i in libgui snavigator/snavigator/unix snavigator
	cd ${WRKSRC}/${i} && ${MAKEINSTALL}
.endfor
.if !defined(NOPORTDOCS)
.for i in examples examples/assembly examples/elf
	cd ${SNSRC}/sdk/parsers/${i} && ${MAKEINSTALL}
.endfor
.endif
.for i in sdk/api parsers/tcl
	cd ${SNSRC}/${i} && ${MAKEINSTALL}
.endfor
	cd ${SNSRC}/parsers/toolbox/ && ${SETENV} ${MAKE_ENV} ${GMAKE} && \
		${INSTALL_DATA} libsnptools.a ${PREFIX}/lib/
	cd ${SNSRC}/parsers/sendmail && ${SETENV} ${MAKE_ENV} ${GMAKE} && \
		${INSTALL_DATA} sbrowser ${PREFIX}/bin/
.for i in libjcreuse java gcj fortran \
	cpp/cpplib \
	cpp common cobol \
	assembly/ppc601-eabi \
	assembly
		cd ${SNSRC}/parsers/${i} && ${MAKEINSTALL}
.endfor
.for i in parsers misc hyper gui etc demo bitmaps
	cd ${SNSRC}/${i} && ${MAKEINSTALL}
.endfor
.for i in tcl8.1/unix tk8.1
	cd ${WRKSRC}/${i} && ${MAKEINSTALL}-binaries install-libraries
.endfor

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
