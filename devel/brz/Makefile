PORTNAME=	brz
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	breezy-${PORTVERSION}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system based on bzr

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}launchpadlib>=0:devel/py-launchpadlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patiencediff>=0:textproc/py-patiencediff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testtools>=0:devel/py-testtools@${PY_FLAVOR}

USES=		gettext python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=		brz
MAKE_ENV=		BRZ_LOG=/dev/null
OPTIONS_DEFINE=		CA_BUNDLE DULWICH SFTP
SFTP_DESC=		Paramiko for SFTP support
CA_BUNDLE_DESC=		Include CA bundle for SSL cert validation
DULWICH_DESC=		Depend on Dulwich for git support
OPTIONS_DEFAULT=	CA_BUNDLE DULWICH

SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
DULWICH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=0:devel/dulwich@${PY_FLAVOR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/brz.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/breezy/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/breezy/bzr/*.so

do-test:
	cd ${WRKSRC} && ./brz selftest

.include <bsd.port.mk>
