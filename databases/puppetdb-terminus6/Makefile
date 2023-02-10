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

BUILD_DEPENDS=	puppet6>=0:sysutils/puppet6

CONFLICTS_INSTALL=	puppetdb-terminus5 puppetdb-terminus7
NO_BUILD=	yes
USES=		gmake ruby

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
