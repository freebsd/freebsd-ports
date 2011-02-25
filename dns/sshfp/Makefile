# New ports collection makefile for:	sshfp
# Date created:				5 Oct 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sshfp
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	dns security
MASTER_SITES=	ftp://ftp.xelerance.com/sshfp/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generate SSHFP DNS records from knownhosts files or ssh-keyscan

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython

NO_BUILD=	yes
USE_PYTHON=	2.5+

LICENSE=	GPLv2

MAN1=		sshfp.1
PLIST_FILES=	bin/sshfp

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
