# $FreeBSD$

PORTNAME=	puppetdb-terminus3
PORTVERSION=	3.2.4
CATEGORIES=	databases ruby
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	freebsd@zleslie.info
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

BUILD_DEPENDS=	puppet:sysutils/puppet4

CONFLICTS_INSTALL=	puppetdb-terminus-* puppetdb-terminus4-*
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet
	(cd ${WRKSRC}/puppet && ${COPYTREE_SHARE} . \
		${STAGEDIR}${RUBY_SITELIBDIR}/puppet)

.include <bsd.port.mk>
