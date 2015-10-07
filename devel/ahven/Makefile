# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ahven
PORTVERSION=	2.4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Ahven%20${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada unit test framework

LICENSE=	ISCL

BUILD_DEPENDS=	adactl:${PORTSDIR}/lang/adacontrol

USES=		ada
ALL_TARGET=	build_all
INSTALL_TARGET=	install_lib
MAKE_ENV+=	OS_VERSION=unix

OPTIONS_DEFINE=	TRACE DOCS
OPTIONS_DEFAULT=TRACE
NO_OPTIONS_SORT=yes

TRACE_DESC=	Build with GNAT-specific symbolic tracing functionality

DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-adadomain>0:${PORTSDIR}/textproc/py-sphinxcontrib-adadomain
DOCS_ALL_TARGET=	docs
DOCS_INSTALL_TARGET=	install_docs

TRACE_EXTRA_PATCHES=	${FILESDIR}/extra-src_ahven-framework.adb

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/ahven/html/_sources
	${RM} ${STAGEDIR}${PREFIX}/share/doc/ahven/html/.buildinfo

.include <bsd.port.mk>
