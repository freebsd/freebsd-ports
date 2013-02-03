# New ports collection makefile for:	py-stevedore
# Date created:		2012-08-19
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stevedore
PORTVERSION=	0.8
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E

post-install:
	@cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
