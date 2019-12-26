# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	conkyemail
PORTVERSION=	2.07
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/28462213/ \
		LOCAL/vg
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email script for conky

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	No longer maintained by upstream

RUN_DEPENDS=	conky:sysutils/conky

USES=		python:2.7
USE_PYTHON=	distutils

NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/src

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/${PORTNAME},${DATADIR},g; \
						s,%%DATADIR%%,${DATADIR},; \
						s,%%PYTHON_CMD%%,${PYTHON_CMD},' \
		conkyEmail  conkyEmail.py setup.py example/conkyrc
	@cd ${WRKSRC} && ${RM} -r example/conkyrc.bak

.include <bsd.port.mk>
