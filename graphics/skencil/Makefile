# New ports collection makefile for:	skencil
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skencil
PORTVERSION=	0.6.16
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sketch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive drawing program

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/Imaging.h:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab \
		${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

CONFFLAGS=	--tk-autoconf --tk-flags="-I${X11BASE}/include -I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4 -L${LOCALBASE}/lib -ltk84 -ltcl84 -L${X11BASE}/lib -lX11"

SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHSCRIPTS=	finishinst.py sk2ppm.py sk2ps.py skconvert.py skencil.py \
		skshow.py

do-configure:
	@(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} setup.py configure ${CONFFLAGS})

do-install:
	@${MKDIR} ${DATADIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; ${TAR} -cf - -X ${FILESDIR}/excludelist ${dir}) | \
	    (cd ${DATADIR}; ${TAR} xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SKETCHSCRIPTS} ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${TAR} cf - ${SKETCHDOCS}) | (cd ${DOCSDIR}; ${TAR} xf -)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/Examples; ${TAR} cf - .) | (cd ${EXAMPLESDIR}; ${TAR} xf -)
.endif
	(cd ${DATADIR}; ${PYTHON_CMD} finishinst.py)
.for exec in sk2ppm sk2ps skconvert skencil skshow
	${SED} -e "s|@DATADIR@|${DATADIR}|g ; \
		 s|@PYTHON_CMD@|${PYTHON_CMD}|g" \
		< ${FILESDIR}/${exec}.in > ${PREFIX}/bin/${exec}
	${CHMOD} ${BINMODE} ${PREFIX}/bin/${exec}
	${CHOWN} ${BINOWN}:${BINGROUP} ${PREFIX}/bin/${exec}
.endfor

.include <bsd.port.mk>
