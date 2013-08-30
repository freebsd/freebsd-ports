# $FreeBSD$

PORTNAME=	virtualenv
PORTVERSION=	1.10.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

PLIST_SUB=	PYVER=${PYTHON_VER} PIPVER=${PIPVER} \
		SETUPTOOLSVER=${SETUPTOOLSVER}

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

PIPVER=	1.4.1
SETUPTOOLSVER=	0.9.8

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PYTHON_REL} >= 320
.include "${FILESDIR}/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
