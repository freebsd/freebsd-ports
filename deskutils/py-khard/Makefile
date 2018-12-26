# $FreeBSD$

PORTNAME=	khard
DISTVERSION=	0.13.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andreas@bilke.org
COMMENT=	Console carddav client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>1.12.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04.21:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer>=0:deskutils/py-vdirsyncer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.9.5:deskutils/py-vobject@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PLIST_FILES=	share/zsh/site-functions/_khard \
		share/zsh/site-functions/_email-khard \
		${EXAMPLESDIR}/khard.conf.example \
		${EXAMPLESDIR}/template_for_contact_creation.yaml

SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_khard \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_email-khard \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/misc/khard/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
