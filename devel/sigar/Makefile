# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sigar
PORTVERSION=	1.7.3
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Sigar system information API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/NOTICE

USE_GITHUB=	yes
GH_ACCOUNT=	amishHammer
GH_COMMIT=	b5af695
GH_TAGNAME=	${GH_COMMIT}

WRKSRC=		${WRKDIR}/amishHammer-sigar-${GH_COMMIT}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf automake aclocal libtoolize
USES=		libtool pkgconfig

run-autotools:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh)

.include <bsd.port.mk>
