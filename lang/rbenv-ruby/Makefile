# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

PORTNAME=	rbenv-ruby
PORTVERSION=	${RUBY_VERSION}.${RUBY_PATCHLEVEL}
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT?=	An object-oriented interpreted scripting language

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	ruby-build:${PORTSDIR}/devel/ruby-build

LATEST_LINK=	${PKGNAME}

RUBY_VERSION?=	1.8.7
RUBY_PATCHLEVEL?=	357

RBCONFIG?=	rbenv_root/versions/1.8.7-p357/lib/ruby/1.8/x86_64-freebsd9.1/rbconfig.rb

do-build:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/install.sh ${WRKSRC}/install.sh
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/install.sh

do-install:
	${FIND} ${WRKSRC}
	${WRKSRC}/install.sh ${RUBY_VERSION}-p${RUBY_PATCHLEVEL}

post-install:
	${REINPLACE_CMD}  -e 's|/opt/gcc|cc|' ${PREFIX}/${RBCONFIG}
	${RM} ${PREFIX}/${RBCONFIG}.bak
	@${SETENV} PKG_PREFIX=${PREFIX} \
	${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
