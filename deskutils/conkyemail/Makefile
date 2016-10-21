# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	conkyemail
PORTVERSION=	2.07
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/28462213/ \
		LOCAL/vg
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Email script for conky

RUN_DEPENDS=	conky:sysutils/conky

USES=		python
USE_PYTHON=	distutils
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/src

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/${PORTNAME},${DATADIR},g' \
		conkyEmail  conkyEmail.py setup.py example/conkyrc
	cd ${WRKSRC} && ${RM} -r example/conkyrc.bak

.include <bsd.port.mk>
