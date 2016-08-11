# $FreeBSD$

PORTNAME=	puppetdb-terminus
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	freebsd@geoffgarside.co.uk
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

BUILD_DEPENDS=	puppet38>=0:sysutils/puppet38

CONFLICTS_INSTALL=	puppetdb-terminus3-* puppetdb-terminus4-*
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet
	(cd ${WRKSRC}/ext/master/lib/puppet && ${COPYTREE_SHARE} . \
		${STAGEDIR}${RUBY_SITELIBDIR}/puppet)

.include <bsd.port.mk>
