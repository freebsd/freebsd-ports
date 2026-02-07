PORTNAME=	puppetdb-terminus
PORTVERSION=	8.8.1
CATEGORIES=	databases ruby
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	8
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module
WWW=		https://docs.puppetlabs.com/puppetdb/latest/

LICENSE=	APACHE20

CONFLICTS_INSTALL=	openvoxdb-terminus[0-9] puppetdb-terminus[0-9]
NO_BUILD=	yes
USES=		gmake ruby

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install-puppetdb-termini

.include <bsd.port.mk>
