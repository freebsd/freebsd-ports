# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	0.13.0
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/unittest.py:${PORTSDIR}/devel/py-unit \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \

USE_PYTHON=	yes
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py
MAN1=		faucet.1 gnusto.1 im.1 manhole.1 mktap.1 twistd.1

post-patch:
	@ ${PERL} -pi -e 's/from pyunit import/import/g' \
	  ${WRKSRC}/bin/runtests ${WRKSRC}/twisted/test/*.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 \
	  --prefix=${PREFIX}
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/man/${manpage} ${MANPREFIX}/man/man1
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/img
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/img/*.bmp ${DOCSDIR}/img
.for docfile in CREDITS ERRATA README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
