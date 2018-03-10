# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ahven
PORTVERSION=	2.6
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.ahven-framework.com/releases/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Ada unit test framework

LICENSE=	ISCL

BUILD_DEPENDS=	adactl:lang/adacontrol

USES=		ada gmake
MAKE_ENV=	OS_VERSION=unix

OPTIONS_DEFINE=		TRACE DOCS
OPTIONS_DEFAULT=	TRACE
NO_OPTIONS_SORT=	yes
TRACE_DESC=		Build with GNAT-specific symbolic tracing functionality

DOCS_USES=		python:2.7,build
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-adadomain>0:textproc/py-sphinxcontrib-adadomain@${PY_FLAVOR}
TRACE_EXTRA_PATCHES=	${FILESDIR}/extra-src_ahven-framework.adb

post-patch:
	@${REINPLACE_CMD} -e 's|sphinx-build|&-${PYTHON_VER}|' ${WRKSRC}/doc/manual/en/Makefile

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
