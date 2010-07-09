# Ports collection makefile for:  postgresql-plproxy
# Date created:    27 July 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	plproxy
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2665/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PL/Proxy is database partitioning system

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_BISON=	build

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000207&release_id=1635

post-patch:
	@${REINPLACE_CMD} -e 's= flex= ${LOCALBASE}/bin/flex=g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
