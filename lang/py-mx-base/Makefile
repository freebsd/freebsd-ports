# New ports collection makefile for:	py-mx-base
# Date created:		18 March 2001
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mx-base
PORTVERSION=	2.0.3
CATEGORIES=	lang python
MASTER_SITES=	http://www.lemburg.com/files/python/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

DOCDIR=		${PREFIX}/share/doc/py-mx
MXHDRDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/mx/stdlib

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install \
	--prefix=${PREFIX})

post-install:
	@${MKDIR} ${DOCDIR}
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCDIR}/index.html
	@${CHMOD} 644 ${DOCDIR}/index.html
	@${MKDIR} ${MXHDRDIR}
.for file in mx.h mxh.h mxpyapi.h mxstdlib.h
	${INSTALL_DATA} ${WRKSRC}/mx/stdlib/${file} ${MXHDRDIR}
.endfor

.include <bsd.port.mk>
