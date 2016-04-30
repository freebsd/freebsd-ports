# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ahven
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.ahven-framework.com/releases/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada unit test framework

LICENSE=	ISCL

BUILD_DEPENDS=	adactl:lang/adacontrol

USES=		ada gmake
MAKE_ENV=	OS_VERSION=unix

OPTIONS_DEFINE=		TRACE DOCS
OPTIONS_DEFAULT=	TRACE
NO_OPTIONS_SORT=	yes
TRACE_DESC=		Build with GNAT-specific symbolic tracing functionality

DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-adadomain>0:textproc/py-sphinxcontrib-adadomain
TRACE_EXTRA_PATCHES=	${FILESDIR}/extra-src_ahven-framework.adb

do-build:
	(cd ${WRKSRC} && ${MKDIR} lib objects)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pgnat/ahven_lib)

do-build-DOCS-on:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} -C doc/manual/en html)

do-install:
	(cd ${STAGEDIR}${PREFIX} && ${MKDIR} lib/gnat lib/ahven include/ahven)
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/ahven
	${INSTALL_DATA} ${WRKSRC}/lib/*.ali ${STAGEDIR}${PREFIX}/lib/ahven
	${INSTALL_DATA} ${WRKSRC}/lib/libahven.a ${STAGEDIR}${PREFIX}/lib/ahven
	${INSTALL_DATA} ${FILESDIR}/ahven.gpr ${STAGEDIR}${PREFIX}/lib/gnat

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/manual/en/build && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR});
	${RM} -r ${STAGEDIR}${DOCSDIR}/html/_sources
	${RM} ${STAGEDIR}${DOCSDIR}/html/.buildinfo

.include <bsd.port.mk>
