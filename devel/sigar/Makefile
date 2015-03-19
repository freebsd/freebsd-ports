# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sigar
PORTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GHL

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Sigar system information API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/NOTICE

USE_GITHUB=	yes
GH_ACCOUNT=	amishHammer
GH_COMMIT=	b5af695
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
