# $FreeBSD$

PORTNAME=	watchdog
PORTVERSION=	0.6.0
#PORTREVISION=	0
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API library to monitor file system events

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}argh>=0.15.1:${PORTSDIR}/devel/py-argh \
		${PKGNAMEPREFIX}yaml>=3.10:${PORTSDIR}/devel/py-yaml \
		${PKGNAMEPREFIX}pathtools>=0.1.2:${PORTSDIR}/devel/py-pathtools

GH_ACCOUNT=	gorakhargosh
GH_COMMIT=	42b5dfe
GH_TAGNAME=	v${PORTVERSION}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
USE_PYDISTUTILS=	easy_install
# Python3 ready (installation tested)
USE_PYTHON=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PKGNAMEPREFIX}pathtools>=0.1.2:${PORTSDIR}/devel/py-pathtools \
		${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-build:
	(cd ${WRKSRC}/docs ; ${MAKE} html)

post-install:
	(cd ${WRKSRC}/docs/build/html ; ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 270 || ${PYTHON_SUFFIX} == 31
RUN_DEPENDS+=	${PKGNAMEPREFIX}argparse>=1.1:${PORTSDIR}/devel/py-argparse
.endif

.if ${PYTHON_REL} >= 320
.include "${.CURDIR}/../py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
