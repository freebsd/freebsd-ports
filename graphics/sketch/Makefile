# New ports collection makefile for:	sketch
# Version required:	0.5.2
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	sketch-0.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.online.de/home/sketch/

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/include/python1.5/Imaging.h:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PREFIX}/lib/python1.5/site-packages/_imaging.so:${PORTSDIR}/graphics/py-imaging

MAKE_FLAGS=	OPT="${CFLAGS}" -f
ALL_TARGET=

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

post-extract:
	${CP} ${FILESDIR}/Setup.Pax ${WRKSRC}/Pax/Setup
	${CP} ${FILESDIR}/Setup.Modules ${WRKSRC}/Sketch/Modules/Setup

do-configure:
	(cd ${WRKSRC}/Pax; ${MAKE} -f Makefile.pre.in boot)
	(cd ${WRKSRC}/Filter; ${MAKE} -f Makefile.pre.in boot)
	(cd ${WRKSRC}/Sketch/Modules; ${MAKE} -f Makefile.pre.in boot)

do-build:
	@(cd ${WRKSRC}/Pax; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKSRC}/Filter; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKSRC}/Sketch/Modules; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${MKDIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; tar -c -f - --exclude-from=${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}/; tar xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} finishinst.py sk2ps.py sketch.py ${SKETCHDIR})
	${MKDIR} ${SKETCHDOCDIR}
	(cd ${WRKSRC}; tar cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; tar xf -)
	${MKDIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; tar cf - .) | (cd ${SKETCHEXDIR}; tar xf -)
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	chmod +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	chmod +x ${PREFIX}/bin/sk2ps

.include <bsd.port.mk>
