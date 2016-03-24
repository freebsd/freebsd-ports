# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mycli
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	databases python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for MySQL Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=4.1:${PORTSDIR}/devel/py-click \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=0.57:${PORTSDIR}/devel/py-prompt_toolkit \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pymysql>=0.6.2:${PORTSDIR}/databases/py-pymysql \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.1.16:${PORTSDIR}/databases/py-sqlparse

NO_ARCH=	yes
USE_MYSQL=	yes
USE_PYTHON=	autoplist distutils
USES=		python

GH_ACCOUNT=	dbcli
GH_TAGNAME=	70f828f
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/prompt_toolkit/ s|==0.57| >= 0.57|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
