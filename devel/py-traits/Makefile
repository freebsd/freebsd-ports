# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	traits
PORTVERSION=	3.6.0
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	http://www.enthought.com/repo/ETS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Traits-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Explicitly Typed Attributes for Python

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}EnthoughtBase>=3.0.1:${PORTSDIR}/devel/py-EnthoughtBase \
		${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${EXAMPLESDIR}/\{} \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;

.include <bsd.port.mk>
