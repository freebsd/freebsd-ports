# New ports collection makefile for:	gmapcatcher
# Date created:		24 March 2010
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmapcatcher
PORTVERSION=	0.7.1.0
CATEGORIES=	astro geography
MASTER_SITES=	http://gmapcatcher.googlecode.com/files/
DISTNAME=	GMapCatcher-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An offline map viewer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_GNOME=	pygtk2

WRKSRC=		${WRKDIR}/${DISTNAME}

DOWNLOAD_PY=	${WRKSRC}/download.py

pre-patch:
	@${TR} -d '\r' < ${DOWNLOAD_PY} > ${DOWNLOAD_PY}.tmp
	@${MV} -f ${DOWNLOAD_PY}.tmp ${DOWNLOAD_PY}

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} {} \;

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.py* ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/src ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/images ${PYTHON_SITELIBDIR}/${PORTNAME}
	${CHMOD} +x ${PYTHON_SITELIBDIR}/${PORTNAME}/maps.py
	${CHMOD} +x ${PYTHON_SITELIBDIR}/${PORTNAME}/download.py
	${LN} -fs ${PYTHON_SITELIBDIR}/${PORTNAME}/maps.py \
		${PREFIX}/bin/gmapcatcher
	${LN} -fs ${PYTHON_SITELIBDIR}/${PORTNAME}/download.py \
		${PREFIX}/bin/gmapcatcher-download

.include <bsd.port.mk>
