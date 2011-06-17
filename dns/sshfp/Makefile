# New ports collection makefile for:	sshfp
# Date created:				5 Oct 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sshfp
PORTVERSION=	1.2.1
CATEGORIES=	dns security
MASTER_SITES=	ftp://ftp.xelerance.com/sshfp/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generate SSHFP DNS records from knownhosts files or ssh-keyscan

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}argparse>=0.8.0:${PORTSDIR}/devel/py-argparse
LIB_DEPENDS+=	ldns:${PORTSDIR}/dns/ldns

NO_BUILD=	yes
USE_PYTHON=	2.5+

LICENSE=	GPLv2

MAN1=		sshfp.1 dane.1
PLIST_FILES=	bin/sshfp bin/dane

PY_FILES=	sshfp dane

post-patch:
.for f in ${PY_FILES}
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${f}
.endfor

do-install:
.for f in ${PY_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
