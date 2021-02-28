# $FreeBSD$

PORTNAME=	puppetdb-terminus
PORTVERSION=	5.2.19
CATEGORIES=	databases ruby
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	5
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

DEPRECATED=	Puppet 5 has reached EOL
EXPIRATION_DATE=2021-07-01

BUILD_DEPENDS=	puppet5>=0:sysutils/puppet5

CONFLICTS_INSTALL=	puppetdb-terminus6-* puppetdb-terminus7-*
USE_RUBY=	yes
NO_BUILD=	yes
USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
