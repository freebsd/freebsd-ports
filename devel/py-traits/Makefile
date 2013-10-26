# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	traits
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.enthought.com/repo/ETS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Traits-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Explicitly Typed Attributes for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}EnthoughtBase>=3.0.1:${PORTSDIR}/devel/py-EnthoughtBase \
		${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

FETCH_ARGS=		-pRr
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Traits
PYEASYINSTALL_ARCHDEP=	yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
