# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	2.7.0.6622
CATEGORIES=	devel
MASTER_SITES=	https://distfiles.over-yonder.net/bzr/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system by Canonical

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testtools>=0:devel/py-testtools@${PY_FLAVOR}

OPTIONS_DEFINE=	SFTP CA_BUNDLE
SFTP_DESC=	Paramiko for SFTP support
CA_BUNDLE_DESC=	Include CA bundle for SSL cert validation
OPTIONS_DEFAULT=	SFTP CA_BUNDLE

SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		gettext python:2.7 shebangfix tar:xz
SHEBANG_FILES=	bzr
USE_PYTHON=	distutils cython autoplist
PYDISTUTILS_PKGNAME=	bzr
MAKE_ENV=	BZR_LOG=/dev/null

WRKSRC=		${WRKDIR}/bzr-2.7.1dev

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bzrlib/*.so

do-test:
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.mk>
