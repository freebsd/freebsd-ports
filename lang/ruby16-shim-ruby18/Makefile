# New ports collection makefile for:	ruby16-shim-ruby18
# Date created:		5 May 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	shim-ruby18
PORTVERSION=	1.8.1.p3
CATEGORIES=	lang devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	shim
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	shim-ruby16_18-1.8.1-preview3
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A set of Ruby modules to provide Ruby 1.8 functionalities

USE_BZIP2=	yes
USE_OPENSSL=	yes

USE_RUBY=	yes

MAKE_ARGS=	RUBY=${RUBY}
#CONFIGURE_ARGS+= CONFIGURE_ARGS="-- --config-opt=--with-opt-dir=${LOCALBASE}"
WRKSRC=		${WRKDIR}/shim/ruby16

RUBY_VER=	1.6

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

INSTALLED_SCRIPTS=	${PREFIX}/bin/erb \
			${PREFIX}/bin/h2rb \
			${PREFIX}/bin/rdoc

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT} \

pre-install:
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
# Make make reinstall work
	${RM} -f ${WRKSRC}/InstalledFiles

post-install:
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	for f in ${INSTALLED_SCRIPTS}; do \
		${LN} -f $${f}${RUBY_SUFFIX} $${f}${RUBY_R}; \
	done
.endif

.include <bsd.port.post.mk>
