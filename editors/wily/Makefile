# New ports collection makefile for: wily
# Version required: 	0.13.36
# Date created:   	23 September 1997
# Whom: 		koshy
#
# $Id: Makefile,v 1.8 1998/11/28 09:07:19 asami Exp $
#

DISTNAME=	wily-0.13.41
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.northsea.com/pub/plan9_unix/wily/src/ \
		ftp://ftp.cs.york.ac.uk/pub/mhw/wily/src/ \
		ftp://ftp.cs.su.oz.au/gary/wily/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkoshy@freebsd.org

USE_XLIB=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

WILYDOCDIR=	${PREFIX}/share/doc/wily
WILYTUTEDIR=	${WILYDOCDIR}/tute
WILYDOCFILES=	index.html intro.html download.html credits.html FAQ.html \
		onepage.html user.html idioms.html C.html python.html \
		hack.html AcmeVsWily.html Tcl.html \
		pythonpaper.html winmanager.html auug.html one.html \
		example.gif thumb.gif cartoon.gif \
		FAQ.txt Tcl.txt changes.txt perl.txt \
		Credits fonts mouse\
		tute/findword tute/script tute/start tute/hello.c \
		tute/send_to_gary

# The default Wily makefile does not install any documentation.  Rectify.
post-install:
	strip ${PREFIX}/bin/wily
.if !defined(NOPORTDOCS)
	${MKDIR} ${WILYDOCDIR} ${WILYTUTEDIR}
	set -e; for f in ${WILYDOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/Doc/$${f} ${WILYDOCDIR}/$${f}; \
	done
.endif

.include <bsd.port.mk>
