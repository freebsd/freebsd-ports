# Created by: Jose Jachuf <jjachuf@gmail.com>
# $FreeBSD$

PORTNAME=	fdb
PORTVERSION=	1.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Firebird RDBMS bindings for Python

LICENSE=	BSD

LIB_DEPENDS=	libfbclient.so:${PORTSDIR}/databases/firebird25-client

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && ${OSVERSION} >= 900000
BROKEN=	Does not compile on FreeBSD 9 i386
.endif

post-patch:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please make sure that your firebird-client installation"
	@${ECHO_MSG} "is built with command make -DPACKAGE_BUILDING."
	@${ECHO_MSG} "The build of py-fdb will fail otherwise."
	@${ECHO_MSG}

.include <bsd.port.post.mk>
