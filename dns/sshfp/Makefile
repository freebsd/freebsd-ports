# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sshfp
PORTVERSION=	1.2.2
CATEGORIES=	dns security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generate SSHFP DNS records from knownhosts files or ssh-keyscan

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}argparse>=0.8.0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}ipcalc>=0.6:${PORTSDIR}/net-mgmt/py-ipcalc \
		${PYTHON_SITELIBDIR}/ldns.py:${PORTSDIR}/dns/py-ldns

NO_BUILD=	yes
USE_PYTHON=	2.5+
USE_GITHUB=	yes
GH_ACCOUNT=	xelerance
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	3378f7d

MAN1=		sshfp.1 dane.1

PY_FILES=	sshfp dane

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}

NO_STAGE=	yes
post-patch:
.for f in ${PY_FILES} daneldnsx.py
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${f}
.endfor

do-install:
.for f in ${PY_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${MANPREFIX}/man/man1
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/daneldnsx.py ${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
