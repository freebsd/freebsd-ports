# New ports collection makefile for:    PIL
# Version required:     0.3b2
# Date created:         02 November 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1998/11/16 08:52:11 tg Exp $
#

DISTNAME=	Imaging-0.3b2
PKGNAME=	py-imaging-0.3b2
CATEGORIES=	graphics python
MASTER_SITES=	http://www.pythonware.com/downloads/ \
		ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pyth151.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

DIST_SUBDIR=	python
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/${DISTNAME}/libImaging
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg=${PREFIX}/lib
MAKE_FLAGS=	OPT="${CFLAGS}"

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
PILDIR=		${PYTHONSCRIPTDIR}/site-packages/PIL
PILDOCDIR=	${PREFIX}/share/doc/PIL
PILEXDIR=	${PREFIX}/share/examples/PIL
PILINCDIR=	${PREFIX}/include/python1.5
TKINTERORIG=	${PYTHONSCRIPTDIR}/lib-dynload/_tkinter.so

post-extract:
	@(cd ${WRKDIR}; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	    ${_DISTDIR}/pyth151.tgz ${EXTRACT_AFTER_ARGS} \
	    Python-1.5.1/Modules/_tkinter.c Python-1.5.1/Modules/tkappinit.c)
	@${MV} ${WRKDIR}/Python-1.5.1/Modules/* ${WRKSRC}/..
	@${CP} ${FILESDIR}/Setup ${WRKSRC}/..

post-configure:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-build:
	@(cd ${WRKSRC}/..; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} sharedmods)

do-install:
	if test -f ${TKINTERORIG}; then \
		${MV} ${TKINTERORIG} ${TKINTERORIG}.save; \
	else true; \
	fi
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
