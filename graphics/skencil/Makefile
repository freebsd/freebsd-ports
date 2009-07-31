# New ports collection makefile for:	skencil
# Date created:		04 November 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skencil
PORTVERSION=	0.6.17
PORTREVISION=	3
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

# Core dump with Python 2.5, see ports/115926.
USE_PYTHON=	-2.4
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes

USE_XORG=	x11 xext

CONFFLAGS=	--tk-autoconf --tk-flags="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4 -L${LOCALBASE}/lib -ltk84 -ltcl84 -L${LOCALBASE}/lib -lX11"

SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHSCRIPTS=	finishinst.py sk2ppm.py sk2ps.py skconvert.py skencil.py \
		skshow.py

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VERSION} != ${PYTHON_DEFAULT_VERSION}
IGNORE=		needs Python ${PYTHON_VER} as default on pointyhat/TB
.endif

do-configure:
	@(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} setup.py configure ${CONFFLAGS})

post-build:
.for exec in sk2ppm sk2ps skconvert skencil skshow
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/${exec}.in
	@${ECHO_CMD} '' >> ${WRKDIR}/${exec}.in
	@${ECHO_CMD} 'exec ${PYTHON_CMD} ${DATADIR}/${exec}.py $$@' >> ${WRKDIR}/${exec}.in
.endfor

do-install:
.for exec in sk2ppm sk2ps skconvert skencil skshow
	${INSTALL_SCRIPT} ${WRKDIR}/${exec}.in ${PREFIX}/bin/${exec}
.endfor
	@${MKDIR} ${DATADIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	${TAR} -C ${WRKSRC} -cf - -X ${FILESDIR}/excludelist ${dir} | \
		${TAR} -C ${DATADIR} -xf -
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SKETCHSCRIPTS} ${DATADIR})
	(cd ${DATADIR}; ${PYTHON_CMD} finishinst.py)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC} -cf - ${SKETCHDOCS} | ${TAR} -C ${DOCSDIR} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/Examples -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
