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
USE_PYTHON=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	xelerance
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	3378f7d

PY_FILES=	sshfp dane

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}

post-patch:
.for f in ${PY_FILES} daneldnsx.py
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${f}
.endfor

do-install:
.for f in ${PY_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/daneldnsx.py ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
