# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/unittest.py:${PORTSDIR}/devel/py-unit

USE_PYTHON=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/twisted

MAN1=		faucet.1 gnusto.1 im.1 mktap.1 twistd.1

post-patch:
	@ ${PERL} -pi.orig -e 's/from pyunit import/import/g' \
	  ${WRKSRC}/bin/runtests ${WRKSRC}/twisted/test/*.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 \
	  --prefix=${PREFIX}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/img
	@ ${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/img/*.bmp ${DOCSDIR}/img
.for docfile in CREDITS LICENSE README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
