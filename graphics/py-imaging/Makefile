# New ports collection makefile for:    PIL
# Version required:     1.0
# Date created:         02 November 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Imaging-1.0
PKGNAME=	py-imaging-1.0
CATEGORIES=	graphics python
MASTER_SITES=	http://www.pythonware.com/downloads/ \
		ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

DIST_SUBDIR=	python
WRKSRC=		${WRKDIR}/${DISTNAME}/libImaging
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg=${PREFIX}/lib
MAKE_FLAGS=	OPT="${CFLAGS}"

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
PILDIR=		${PYTHONSCRIPTDIR}/site-packages/PIL
PILDOCDIR=	${PREFIX}/share/doc/PIL
PILEXDIR=	${PREFIX}/share/examples/PIL
PILINCDIR=	${PREFIX}/include/python1.5

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}/..

post-configure:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-build:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} sharedmods)

do-install:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} install)
	@${MKDIR} ${PILDIR}
	${INSTALL_DATA} ${WRKSRC}/../PIL/* ${PILDIR}
	${INSTALL_DATA} ${WRKSRC}/../PIL.pth ${PILDIR}/..
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${PILDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${PILDIR}
	@${MKDIR} ${PILDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${PILDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../FORMATS ${PILDOCDIR}
	@${MKDIR} ${PILEXDIR}
	${INSTALL_DATA} ${WRKSRC}/../Scripts/* ${PILEXDIR}
.for file in ImConfig.h ImPlatform.h Imaging.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PILINCDIR}
.endfor

.include <bsd.port.mk>
