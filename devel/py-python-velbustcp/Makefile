PORTNAME=		python-velbustcp
DISTVERSION=		2.0.0
CATEGORIES=		devel python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Python application that bridges a Velbus installation with TCP
WWW=		https://github.com/velbus/python-velbustcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	velbus
USE_PYTHON=	autoplist concurrent distutils

USE_RC_SUBR=	velbustcpd

NO_ARCH=	yes
SUB_LIST=	PORTNAME=${PORTNAME} \
		PYTHON_CMD=${PYTHON_CMD} \
		USERS=${USERS}

USERS=		velbustcpd
GROUPS=		velbustcpd

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/settings.json.template ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/settings.json.sample
	${ECHO_CMD} "@sample etc/${PORTNAME}/settings.json.sample" >> ${TMPPLIST}
	${INSTALL_DATA} files/velbustcpd-devd.conf ${STAGEDIR}${PREFIX}/etc/devd/velbustcpd-devd.conf.sample
	${ECHO_CMD} "@sample etc/devd/velbustcpd-devd.conf.sample" >> ${TMPPLIST}

.include <bsd.port.mk>
