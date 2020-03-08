# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshfp
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	dns security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generate SSHFP DNS records from knownhosts files or ssh-keyscan

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipcalc>=0.6:net-mgmt/py-ipcalc@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/ldns.py:dns/py-ldns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:2.7 shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	xelerance

NO_ARCH=	yes
NO_BUILD=	yes

PY_FILES=	sshfp dane
SHEBANG_FILES=	daneldnsx.py ${PY_FILES}

do-install:
.for f in ${PY_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/daneldnsx.py ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
