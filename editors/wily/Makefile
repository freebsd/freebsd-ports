# New ports collection makefile for: wily
# Date created:   	23 September 1997
# Whom: 		koshy
#
# $FreeBSD$
#

PORTNAME=	wily
PORTVERSION=	0.13.41
PORTREVISION=	1
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/src/old/ \
		ftp://ftp.math.tau.ac.il/pub/laden/wily/src/ \
		ftp://ftp.cs.su.oz.au/gary/wily/src/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@pompo.net
COMMENT=	A clone of the Plan9 editor `acme'

RUN_DEPENDS=	${LOCALBASE}/bin/rc:${PORTSDIR}/shells/rc

USE_XLIB=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAN1=		wgoto.1 win.1 wreplace.1 Tag.1 mktags.1 Man.1

# Run the configure script in the tools directory.
post-configure:
	${RM} ${WRKSRC}/tools/win/config.cache
	cd ${WRKSRC}/tools/win; ./configure

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
	${STRIP_CMD} ${PREFIX}/bin/wily
.if !defined(NOPORTDOCS)
	${MKDIR} ${WILYDOCDIR} ${WILYTUTEDIR}
	set -e; for f in ${WILYDOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/Doc/$${f} ${WILYDOCDIR}/$${f}; \
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
