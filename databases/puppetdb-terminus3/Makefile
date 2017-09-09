# $FreeBSD$

PORTNAME=	puppetdb-terminus3
PORTVERSION=	3.2.4
CATEGORIES=	databases ruby
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/
DISTNAME=	puppetdb-${PORTVERSION}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend terminus module

LICENSE=	APACHE20

DEPRECATED=	End of life upstream
EXPIRATION_DATE=	2017-11-01

BUILD_DEPENDS=	puppet:sysutils/puppet4

CONFLICTS_INSTALL=	puppetdb-terminus4-* puppetdb-terminus5-*
USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/puppet
	(cd ${WRKSRC}/puppet && ${COPYTREE_SHARE} . \
		${STAGEDIR}${RUBY_SITELIBDIR}/puppet)

.include <bsd.port.mk>
