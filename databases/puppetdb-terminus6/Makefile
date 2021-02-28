# $FreeBSD$

PORTNAME=	puppetdb-terminus
PORTVERSION=	6.15.0
CATEGORIES=	databases ruby
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	6
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

BUILD_DEPENDS=	puppet6>=0:sysutils/puppet6

CONFLICTS_INSTALL=	puppetdb-terminus5-* puppetdb-terminus7-*
USE_RUBY=	yes
NO_BUILD=	yes
USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
