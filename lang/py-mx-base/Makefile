# New ports collection makefile for:	py-mx-base
# Date created:		18 March 2001
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mx-base
PORTVERSION=	2.0.0
CATEGORIES=	lang python
MASTER_SITES=	http://www.lemburg.com/python/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

DOCDIR=		${PREFIX}/share/doc/py-mx

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)

post-install:
.for dir in DateTime Proxy Stack TextTools Tools
	@cd ${PYTHON_SITELIBDIR} && ${LN} -sf mx/${dir} ${dir}
.endfor
	@${MKDIR} ${DOCDIR}
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCDIR}/index.html
	@${CHMOD} 644 ${DOCDIR}/index.html

.include <bsd.port.mk>
