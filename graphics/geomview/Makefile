# New ports collection makefile for:	geomview
# Version required:			1.6.1
# Date created:				5 November 1996
# Whom:					fenner
#
# $Id: Makefile,v 1.13 1999/01/07 08:19:38 simokawa Exp $

DISTNAME=	geomview-1.6.1
CATEGORIES=	graphics tk80
MASTER_SITES=	ftp://ftp.geom.umn.edu/pub/software/geomview/	\
		ftp://ftp-sfb288.math.tu-berlin.de/pub/geomview/
DISTFILES=	geomview-1.6.1-src.tar.gz

MAINTAINER=	fenner@freebsd.org

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

# depends on xforms
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/Geomview
REQUIRES_MOTIF=	yes
USE_X_PREFIX=	yes

MAN1=		addbbox.1 animate.1 anytooff.1 anytoucd.1 bdy.1 clip.1 \
		cplxview.1 crayola.1 example.1 flythrough.1 geomview.1 \
		ginsu.1 graffiti.1 hinge.1 hvectext.1 maniview.1 nose.1 \
		offconsol.1 polymerge.1 sweep.1 tackdown.1 togeomview.1 \
		transformer.1 ucdtooff.1
MAN3=		anytopl.3 bdy.3 fsaparse.3 geomutil.3 lisp.3 plcombine.3 \
		plconsol.3 pointlist.3 sweep.3
MAN5=		discgrp.5 geomview.5 oogl.5

# Set CPU type for Geomview make
# Add ${FILESDIR} to PATH for "make install"
# Allow user to specify "make install MAPLE_LIB=foo" as geomview wants
MAKE_ENV=	CPU=FreeBSD PATH=${FILESDIR}:${PATH} MAPLE_LIB=${MAPLE_LIB}

post-extract:
	/bin/chmod +x ${FILESDIR}/nroff

pre-install:
	${MKDIR} ${PREFIX}/share/geomview

# Geomview presumes that you're installing in the source directory,
# so massive parts of the source directory have to be copied to the
# destination.
INFO_FILES=	geomview geomview-1 geomview-2 geomview-3 geomview-4 geomview-5
DOC_FILES=	OOGL.m.doc geomview.tex geomview_toc.html geomview_1.html \
		geomview_2.html geomview_3.html geomview_4.html \
		geomview_5.html geomview_6.html geomview_7.html \
		geomview_8.html geomview_9.html geomview_10.html \
		geomview_11.html geomview_12.html geomview_13.html \
		gvplot.doc newsletter_article.txt oogltour
EXAMPLE_FILES=	example1.c example2.c example3.c example4.tcl
MAN_FILES=	geomview.5 oogl.5
SHARE_DIRS=	data maple mathematica
SHARE_MODS=	tcl
LIBEXEC_DIRS=	bin
LIBEXEC_MODS=	x11

CHOWN?=		/usr/sbin/chown

post-install:
	${MKDIR} ${PREFIX}/info
.for i in ${INFO_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/info
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/geomview
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/geomview
.endfor
	${MKDIR} ${PREFIX}/share/examples/geomview
.for i in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/examples/geomview
.endfor
.endif
.for i in ${MAN_FILES}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${PREFIX}/man/man5
.endfor
.for i in ${SHARE_DIRS}
	${RM} -rf ${PREFIX}/share/geomview/${i}
	${MKDIR} ${PREFIX}/share/geomview/${i}
	${CP} -pr ${WRKSRC}/${i} ${PREFIX}/share/geomview
	${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${PREFIX}/share/geomview/${i}
.endfor
.for i in ${SHARE_MODS}
	${RM} -rf ${PREFIX}/share/geomview/modules/${i}
	${MKDIR} ${PREFIX}/share/geomview/modules/${i}
	${CP} -pr ${WRKSRC}/modules/${i} ${PREFIX}/share/geomview/modules
	${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${PREFIX}/share/geomview/modules/${i}
.endfor
.for i in ${LIBEXEC_DIRS}
	${RM} -rf ${PREFIX}/libexec/geomview/${i}
	${MKDIR} ${PREFIX}/libexec/geomview/${i}
	${CP} -pr ${WRKSRC}/${i} ${PREFIX}/libexec/geomview/
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/libexec/geomview/${i}
.endfor
.for i in ${LIBEXEC_MODS}
	${RM} -rf ${PREFIX}/libexec/geomview/modules/${i}
	${MKDIR} ${PREFIX}/libexec/geomview/modules/${i}
	${CP} -pr ${WRKSRC}/modules/${i} ${PREFIX}/libexec/geomview/modules
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/libexec/geomview/modules/${i}
.endfor

.include <bsd.port.mk>
