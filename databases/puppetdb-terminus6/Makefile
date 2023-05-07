PORTNAME=	puppetdb-terminus
PORTVERSION=	6.22.1
CATEGORIES=	databases ruby
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	6
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module
WWW=		https://docs.puppetlabs.com/puppetdb/latest/

LICENSE=	APACHE20

DEPRECATED=	Puppet 6 has reached EOL
EXPIRATION_DATE=2023-06-01

CONFLICTS_INSTALL=	puppetdb-terminus[0-9]
NO_BUILD=	yes
USES=		gmake ruby

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
