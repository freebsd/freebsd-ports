# Created by: Jose Jachuf <jjachuf@gmail.com>
# $FreeBSD$

PORTNAME=	fdb
PORTVERSION=	1.8
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Firebird RDBMS bindings for Python

LICENSE=	ISCL

NO_ARCH=	yes
USES=		firebird python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please make sure that your firebird-client installation"
	@${ECHO_MSG} "is built with command make -DPACKAGE_BUILDING."
	@${ECHO_MSG} "The build of py-fdb will fail otherwise."
	@${ECHO_MSG}

.include <bsd.port.post.mk>
