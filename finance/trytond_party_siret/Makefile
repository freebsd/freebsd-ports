# Created by: Matthias Petermann<matthias@petermann.it>
# $FreeBSD$

PORTNAME=	trytond_party_siret
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Party Siret Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_party>=2.4.0:${PORTSDIR}/finance/trytond_party

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
