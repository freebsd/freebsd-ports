# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system by Canonical

# Often not needed, but it's cheap insurance
BUILD_DEPENDS=	cython:lang/cython

OPTIONS_DEFINE=	SFTP CA_BUNDLE
SFTP_DESC=	Paramiko for SFTP support
CA_BUNDLE_DESC=	Include CA bundle for SSL cert validation
OPTIONS_DEFAULT=	SFTP CA_BUNDLE

SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	bzr
USES=		gettext python:2
MAKE_ENV=	BZR_LOG=/dev/null

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bzrlib/*.so

test:	build
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.mk>
