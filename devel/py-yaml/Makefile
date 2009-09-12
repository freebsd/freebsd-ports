# ex:ts=8
# Ports collection makefile for:	py-yaml
# Date created:			Jan 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yaml
PORTVERSION=	3.09
CATEGORIES=	devel python
MASTER_SITES=	http://pyyaml.org/download/pyyaml/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyYAML-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python YAML parser

OPTIONS=	YAML "Enable LibYAML binding" Off

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyYAML

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/)
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_YAML)
PYSETUP=	setup.py --with-libyaml
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=	--include-dirs=${LOCALBASE}/include \
			--library-dirs=${LOCALBASE}/lib

LIB_DEPENDS+=		yaml-0.2:${PORTSDIR}/textproc/libyaml

PLIST_SUB+=	YAML=""
.else
PYSETUP=	setup.py --without-libyaml

PLIST_SUB+=	YAML="@comment "
.endif

.include <bsd.port.post.mk>
