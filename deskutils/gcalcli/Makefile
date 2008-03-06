# ex:ts=8
# Ports collection makefile for:	gcalcli
# Date created:			Oct 2, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gcalcli
PORTVERSION=	1.4
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Google Calendar Command Line Interface

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gdata/__init__.py:${PORTSDIR}/devel/py-gdata \
		${PYTHON_SITELIBDIR}/dateutil/__init__.py:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/gcalcli

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${SETENV} python," ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
