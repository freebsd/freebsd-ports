# New ports collection makefile for: wily
# Version required: 	0.13.36
# Date created:   	23 September 1997
# Whom: 		koshy
#
# $Id: Makefile,v 1.1.1.1 1997/11/17 11:53:02 tg Exp $
#

DISTNAME=	wily-0.13.36
CATEGORIES=	plan9 editors
MASTER_SITES=	ftp://ftp.northsea.com/pub/plan9_unix/wily/wily/src/ \
		ftp://ftp.cs.york.ac.uk/pub/mhw/wily/src/ \
		ftp://ftp.cs.su.oz.au/gary/wily/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkoshy@freebsd.org

USE_X11=	YES
GNU_CONFIGURE=	YES

WILYDOCDIR=	${PREFIX}/share/doc/wily
WILYDOCFILES=	index.html intro.html download.html credits.html FAQ.txt \
		onepage.html user.html idioms.html C.html python.html \
		perl.txt hack.html changes.txt AcmeVsWily.html Tcl.html \
		pythonpaper.html winmanager.html

# The default Wily makefile does not install any documentation.  Rectify.
post-install:
	strip ${PREFIX}/bin/wily
.if !defined(NOPORTDOCS)
	${MKDIR} ${WILYDOCDIR}
	set -e; for f in ${WILYDOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/Doc/$${f} ${WILYDOCDIR}/$${f}; \
	done
.endif

.include <bsd.port.mk>
