# New ports collection makefile for:	sketch
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sketch
PORTVERSION=	0.6.5
CATEGORIES=	graphics
MASTER_SITES=	http://download.sourceforge.net/sketch/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/python1.5/Imaging.h:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${LOCALBASE}/lib/python1.5/site-packages/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/lib/python1.5/site-packages/xml/__init__.py:${PORTSDIR}/textproc/py-xml

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

post-patch:
	@${PERL} -pi -e "s;%%PORTSDIR%%;${PORTSDIR};" ${WRKSRC}/setup.py

do-configure:
	@(cd ${WRKSRC} && python setup.py configure)

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} python setup.py build)

do-install:
	@${MKDIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; ${TAR} -cf - -X ${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}; ${TAR} xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} finishinst.py sk2ps.py sketch.py ${SKETCHDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${SKETCHDOCDIR}
	(cd ${WRKSRC}; ${TAR} cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; ${TAR} xf -)
.endif
	@${MKDIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; ${TAR} cf - .) | (cd ${SKETCHEXDIR}; ${TAR} xf -)
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sk2ps

.include <bsd.port.mk>
