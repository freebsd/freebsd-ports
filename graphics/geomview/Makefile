# New ports collection makefile for:	geomview
# Date created:				5 November 1996
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	geomview
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	geomview

MAINTAINER=	bms@FreeBSD.org
COMMENT=	An interactive viewer for 3- and 4-D geometric objects

USE_MOTIF=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes

USE_AUTOCONF_VER=	213

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl=${X11BASE}

MANCOMPRESSED=	no
MAN1=		geomview.1 togeomview.1 bdy.1 oogl2rib.1 anytooff.1 \
		bez2mesh.1 offconsol.1 polymerge.1 vrml2oogl.1 clip.1 \
		math2oogl.1 oogl2vrml.1 anytoucd.1 ucdtooff.1
MAN3=		lisp.3
MAN5=		oogl.5 geomview.5

MAN_FILES=	oogl.5 geomview.5
DOC_FILES=	gvplot.txt oogltour OOGL.m.txt README

EXAMPLE_FILES=	example1.c example2.c example3.c example4.tcl

# Set "CPU" type for Geomview make
# Allow user to specify "make install MAPLE_LIB=foo" as geomview wants
MAKE_ENV=	CPU=FreeBSD MAPLE_LIB=${MAPLE_LIB}

AC_FAKE_FILES=	aclocal.m4 config.h.in stamp-h stamp-h.in

post-configure:
	cd ${WRKSRC}; ${TOUCH} ${AC_FAKE_FILES}
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${TOUCH}

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for i in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${EXAMPLESDIR}
.endfor
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man3
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${DOCSDIR}/figs ${DOCSDIR}/html \
	    ${DOCSDIR}/html/pix
.for i in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/figs/*.ps ${DOCSDIR}/figs
	${INSTALL_MAN} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/html/pix/*.gif ${DOCSDIR}/html/pix
.endif

.include <bsd.port.mk>
