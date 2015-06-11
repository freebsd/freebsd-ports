# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	gems
PORTVERSION=	2.4.8
CATEGORIES=	devel ruby
MASTER_SITES=	http://production.cf.rubygems.org/rubygems/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Package management framework for the Ruby language

LICENSE=	MIT RUBY
LICENSE_COMB=	dual

USE_RUBY=	yes
RUBY_SETUP=	setup.rb

NO_BUILD=	yes
USES=		tar:tgz

GEMS_BASE_DIR=		lib/ruby/gems
GEMS_BASE_DIR_P=	${GEMS_BASE_DIR}
GEMS_VER_DIR=		${GEMS_BASE_DIR}/${RUBY_VER}
GEMS_VER_DIR_P=		${GEMS_BASE_DIR_P}/%%RUBY_VER%%
GEMS_DOC_BASE_DIR=	${GEMS_VER_DIR}/doc
GEMS_DOC_BASE_DIR_P=	${GEMS_VER_DIR_P}/doc
GEMS_DOC_DIR=		${GEMS_DOC_BASE_DIR}/${DISTNAME}
GEMS_DOC_DIR_P=		${GEMS_DOC_BASE_DIR_P}/%%DISTNAME%%
RUBY_VER_SHORT=		${RUBY_VER:S/.//}

GEMS_DIR=		${GEMS_VER_DIR}/gems
DOC_DIR=		${GEMS_VER_DIR}/doc
CACHE_DIR=		${GEMS_VER_DIR}/cache
SPEC_DIR=		${GEMS_VER_DIR}/specifications
EXT_DIR=		${GEMS_VER_DIR}/extensions

PLIST_SUB+=	DISTNAME="${DISTNAME}" \
		RUBY_VER_SHORT="${RUBY_VER_SHORT}" \
		GEMS_DIR="${GEMS_DIR}" \
		DOC_DIR="${DOC_DIR}" \
		CACHE_DIR="${CACHE_DIR}" \
		SPEC_DIR="${SPEC_DIR}" \
		EXT_DIR="${EXT_DIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

RUBY_SETUP_OPTIONS=	--destdir=${STAGEDIR}
GEM_ENV=		GEM_HOME=${STAGEDIR}${PREFIX}/${GEMS_VER_DIR}

.if !${PORT_OPTIONS:MDOCS}
RUBY_SETUP_OPTIONS+=	--no-ri --no-rdoc
.endif

do-install:
	cd ${WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBY} ${RUBY_SETUP} ${RUBY_SETUP_OPTIONS}

post-install:
	@${LN} -sf gem${RUBY_VER_SHORT} ${STAGEDIR}${PREFIX}/bin/gem

#
# Find all RDOC and RI files
#
.if ${PORT_OPTIONS:MDOCS}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${GEMS_DOC_DIR}/ ! -type d | \
	    ${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
