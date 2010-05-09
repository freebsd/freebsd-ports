# New ports collection makefile for:	conkyemail
# Date created:		2010-05-08
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	conkyemail
PORTVERSION=	2.07
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/28462213/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Email script for conky

RUN_DEPENDS=	conky:${PORTSDIR}/sysutils/conky

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
INSTALL_EGGINFO=yes

WRKSRC=		${WRKDIR}/src

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/${PORTNAME},${DATADIR},g' \
		conkyEmail  conkyEmail.py setup.py example/conkyrc
	cd ${WRKSRC} && ${RM} -fr example/conkyrc.bak

.include <bsd.port.mk>
