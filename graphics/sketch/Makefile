# New ports collection makefile for:	sketch
# Version required:	0.6.3
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	sketch-0.6.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.online.de/home/sketch/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/include/python1.5/Imaging.h:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PREFIX}/lib/python1.5/site-packages/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		${PREFIX}/lib/python1.5/site-packages/xml/__init__.py:${PORTSDIR}/textproc/py-xml

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

do-configure:
	@(cd ${WRKSRC} && python setup.py configure)

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} python setup.py build)

do-install:
	${MKDIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; tar -c -f - --exclude-from=${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}/; tar xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} finishinst.py sk2ps.py sketch.py ${SKETCHDIR})
.if !defined(NOPORTDOCS)
	${MKDIR} ${SKETCHDOCDIR}
	(cd ${WRKSRC}; tar cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; tar xf -)
.endif
	${MKDIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; tar cf - .) | (cd ${SKETCHEXDIR}; tar xf -)
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} +x ${PREFIX}/bin/sk2ps

.include <bsd.port.mk>
