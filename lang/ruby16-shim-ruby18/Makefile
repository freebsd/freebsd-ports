# New ports collection makefile for:	ruby16-shim-ruby18
# Date created:		5 May 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	shim-ruby18
PORTVERSION=	1.7.3.2002.12.11
PORTREVISION=	1
CATEGORIES=	lang devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	shim
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	shim-ruby16_18-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_BZIP2=	yes

USE_RUBY=	yes

CONFIGURE_ARGS=	RUBY=${RUBY}
#CONFIGURE_ARGS+= CONFIGURE_ARGS="-- --config-opt=--with-opt-dir=${LOCALBASE}"
WRKSRC=		${WRKDIR}/shim/ruby16

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 1.7
IGNORE=		is only for ruby 1.6, ruby ${RUBY_VER} does not need it
.endif

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
IF_DEFAULT=	""
.else
IF_DEFAULT=	"@comment "
.endif

INSTALLED_SCRIPTS=	${PREFIX}/bin/erb \
			${PREFIX}/bin/h2rb

PLIST_SUB+=	IF_DEFAULT=${IF_DEFAULT} \

post-extract:
	${MV} ${WRKSRC}/ext/dl/h2rb ${WRKSRC}/bin/

pre-install:
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
	for f in ${INSTALLED_SCRIPTS}; do \
		${LN} -f $${f}${RUBY_R} $${f}${_RUBY_SUFFIX}; \
	done
.endif


.include <bsd.port.post.mk>
