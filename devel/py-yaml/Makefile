# Created by: ijliao@FreeBSD.org
# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	3.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyYAML-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python YAML parser

LICENSE=	MIT

OPTIONS_DEFINE=	LIBYAML EXAMPLES
LIBYAML_DESC=	Use textproc/libyaml for faster parsing

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)
.endif

.if ${PORT_OPTIONS:MLIBYAML}
PYDISTUTILS_SETUP+=		--with-libyaml
PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=		--include-dirs=${LOCALBASE}/include \
				--library-dirs=${LOCALBASE}/lib
LIB_DEPENDS+=			libyaml.so:${PORTSDIR}/textproc/libyaml
.else
PYDISTUTILS_SETUP+=		--without-libyaml
.endif

.include <bsd.port.post.mk>
