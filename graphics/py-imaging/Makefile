# New ports collection makefile for:    PIL
# Date created:         02 November 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imaging
PORTVERSION=	1.1.2
CATEGORIES=	graphics python
MASTER_SITES=	http://www.pythonware.com/downloads/ \
		ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

DIST_SUBDIR=	python
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/libImaging
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg=${PREFIX}/lib
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
MAKE_FLAGS=	OPT="${CFLAGS}"

PILDIR=		${PYTHON_SITELIBDIR}/PIL
PILDOCDIR=	${PREFIX}/share/doc/PIL
PILEXDIR=	${PREFIX}/share/examples/PIL
PILINCDIR=	${PREFIX}/include/${PYTHON_VERSION}

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}/..

post-configure:
	@(cd ${WRKSRC}/..; ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-build:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} sharedmods)

do-install:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} install)
	@${MKDIR} ${PILDIR}
	${INSTALL_DATA} ${WRKSRC}/../PIL/* ${PILDIR}
	${INSTALL_DATA} ${WRKSRC}/../PIL.pth ${PILDIR}/..
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PILDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PILDIR}
	@${MKDIR} ${PILDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${PILDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/../FORMATS ${PILDOCDIR}
	@${MKDIR} ${PILEXDIR}
	${INSTALL_DATA} ${WRKSRC}/../Scripts/* ${PILEXDIR}
.for file in ImConfig.h ImPlatform.h Imaging.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PILINCDIR}
.endfor

.include <bsd.port.mk>
