PORTNAME=	gems
PORTVERSION=	3.7.1
CATEGORIES=	devel ruby
MASTER_SITES=	https://rubygems.org/rubygems/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubygems-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Package management framework for the Ruby language
WWW=		https://rubygems.org/ \
		https://github.com/rubygems/rubygems

LICENSE=	MIT RUBY
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/MIT.txt
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

USES=		cpe ruby tar:tgz

GEMS_BASE_DIR=	lib/ruby/gems/${RUBY_VER}
GEMS_ENV=	GEM_HOME=${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}
NO_ARCH=	yes
NO_BUILD=	yes
RUBY_SETUP=	setup.rb
RUBY_SETUP_OPTIONS=	--destdir=${STAGEDIR} \
			--no-format-executable \
			--no-regenerate-binstubs \
			--no-regenerate-plugins

CACHE_DIR=	${GEMS_BASE_DIR}/cache
DOC_DIR=	${GEMS_BASE_DIR}/doc
EXT_DIR=	${GEMS_BASE_DIR}/extensions
GEMS_DIR=	${GEMS_BASE_DIR}/gems
PLUGINS_DIR=	${GEMS_BASE_DIR}/plugins
SPEC_DIR=	${GEMS_BASE_DIR}/specifications

PLIST_SUB=	CACHE_DIR="${CACHE_DIR}" \
		DOC_DIR="${DOC_DIR}" \
		EXT_DIR="${EXT_DIR}" \
		GEMS_DIR="${GEMS_DIR}" \
		PLUGINS_DIR="${PLUGINS_DIR}" \
		SPEC_DIR="${SPEC_DIR}"

CPE_VENDOR=	rubygems
CPE_PRODUCT=	rubygems

OPTIONS_DEFINE=	DOCS

DOCS_VARS_OFF=	RUBY_SETUP_OPTIONS+="--no-ri --no-rdoc"

post-extract:
	@${RM} -r ${WRKSRC}/bundler
	@${FIND} ${WRKSRC} -name .document -delete

post-patch:
	@${RM} ${WRKSRC}/lib/rubygems/commands/setup_command.rb.orig

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/build_info
	${MKDIR} ${STAGEDIR}${PREFIX}/${CACHE_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${DOC_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${EXT_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${GEMS_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGINS_DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${SPEC_DIR}
	cd ${WRKSRC}/ && ${SETENV} ${GEMS_ENV} ${RUBY} ${RUBY_SETUP} ${RUBY_SETUP_OPTIONS}

# Find all RDOC and RI files
post-install-DOCS-on:
	cd ${STAGEDIR}${PREFIX}/ && ${FIND} -ds ${DOC_DIR}/ ! -type d >> ${TMPPLIST}

.include <bsd.port.mk>
