# New ports collection makefile for:	sketch
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sketch
PORTVERSION=	0.6.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/Imaging.h:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab \
		${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

CONFFLAGS=	--tk-autoconf --tk-flags="-I${X11BASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 -L${LOCALBASE}/lib -ltk83 -ltcl83 -L${X11BASE}/lib -lX11"

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch
SKETCHSCRIPTS=	finishinst.py sk2ppm.py sk2ps.py skconvert.py sketch.py \
		skshow.py

do-configure:
	@(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} setup.py configure ${CONFFLAGS})

do-install:
	@${MKDIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; ${TAR} -cf - -X ${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}; ${TAR} xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SKETCHSCRIPTS} ${SKETCHDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${SKETCHDOCDIR}
	(cd ${WRKSRC}; ${TAR} cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; ${TAR} xf -)
.endif
	@${MKDIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; ${TAR} cf - .) | (cd ${SKETCHEXDIR}; ${TAR} xf -)
	(cd ${SKETCHDIR}; ${PYTHON_CMD} finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" -e "s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/sk2ppm.in > ${PREFIX}/bin/sk2ppm
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sk2ppm
	${SED} -e "s|@PREFIX@|${PREFIX}|g" -e "s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sk2ps
	${SED} -e "s|@PREFIX@|${PREFIX}|g" -e "s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/skconvert.in > ${PREFIX}/bin/skconvert
	${CHMOD} ${BINMODE} ${PREFIX}/bin/skconvert
	${SED} -e "s|@PREFIX@|${PREFIX}|g" -e "s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} ${BINMODE} ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" -e "s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/skshow.in > ${PREFIX}/bin/skshow
	${CHMOD} ${BINMODE} ${PREFIX}/bin/skshow

.include <bsd.port.mk>
