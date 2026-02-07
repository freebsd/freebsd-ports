PORTNAME=	openvoxdb-terminus
PORTVERSION=	8.11.0
CATEGORIES=	databases ruby
MASTER_SITES=	https://artifacts.voxpupuli.org/openvoxdb/${PORTVERSION}/
PKGNAMESUFFIX=	8
DISTNAME=	openvoxdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module
WWW=		https://docs.puppetlabs.com/puppetdb/latest/

LICENSE=	APACHE20

CONFLICTS_INSTALL=	openvoxdb-terminus[0-9] puppetdb-terminus[0-9]
NO_BUILD=	yes
USES=		gmake ruby
WRKSRC=		${WRKDIR}/puppetdb-${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} puppet ${STAGEDIR}${RUBY_SITELIBDIR}

.include <bsd.port.mk>
