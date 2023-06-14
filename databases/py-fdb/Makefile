PORTNAME=	fdb
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Firebird RDBMS bindings for Python
WWW=		https://pythonhosted.org/fdb/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		firebird python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please make sure that your firebird-client installation"
	@${ECHO_MSG} "is built with command make -DPACKAGE_BUILDING."
	@${ECHO_MSG} "The build of py-fdb will fail otherwise."
	@${ECHO_MSG}

.include <bsd.port.mk>
