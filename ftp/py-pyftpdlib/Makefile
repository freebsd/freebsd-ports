# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pyftpdlib
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	ftp python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python FTP server library

LICENSE=	MIT

USES=		python:2
USE_PYTHON=	distutils

OPTIONS_DEFINE=		SENDFILE OPENSSL EXAMPLES
OPTIONS_DEFAULT=	SENDFILE OPENSSL
SENDFILE_DESC=		Enable sendfile(2) support
OPENSSL_DESC=		Enable FTP over SSL/TLS (RFC4217)

SENDFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysendfile>0:net/py-pysendfile
OPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/demo/ ${STAGEDIR}${EXAMPLESDIR}

test: build
	${TOUCH} ${WRKSRC}/test/__init__.py
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
