# $FreeBSD$

PORTNAME=	pyftpdlib
PORTVERSION=	1.5.6
CATEGORIES=	ftp python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python FTP server library

LICENSE=	MIT

USES=		python shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	demo/*.py
NO_ARCH=	yes

OPTIONS_DEFINE=		SENDFILE OPENSSL EXAMPLES
OPTIONS_DEFAULT=	SENDFILE OPENSSL
SENDFILE_DESC=		Enable sendfile(2) support
OPENSSL_DESC=		Enable FTP over SSL/TLS (RFC4217)

SENDFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysendfile>0:net/py-pysendfile@${PY_FLAVOR}
OPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/demo/ ${STAGEDIR}${EXAMPLESDIR}

test: build
	cd ${WRKSRC}/pyftpdlib && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
