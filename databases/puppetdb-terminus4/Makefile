# $FreeBSD$

PORTNAME=	puppetdb-terminus
PORTVERSION=	4.4.0
CATEGORIES=	databases ruby
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	4
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

DEPRECATED=	Puppet 4 has reached EOL
EXPIRATION_DATE=2019-02-28

BUILD_DEPENDS=	puppet4>=0:sysutils/puppet4

CONFLICTS_INSTALL=	puppetdb-terminus5-* puppetdb-terminus6-*
USE_RUBY=	yes
NO_BUILD=	yes
USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
