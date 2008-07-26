# New ports collection makefile for:	dosage
# Date created:				6 February 2005
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	dosage
PORTVERSION=	1.6.0
CATEGORIES=	deskutils python
MASTER_SITES=	http://slipgate.za.net/dosage/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	An application to keep a local mirror of web comics

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Dosage
USE_TWISTED_RUN=yes
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0_1:${PORTSDIR}/devel/py-zopeInterface

MAN1=		mainline.1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
	${WRKSRC}/doc/mainline.1 \
	${WRKSRC}/dosage/scraper.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/mainline.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
