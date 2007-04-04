# Ports collection makefile for:	gem-activerecord
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	1.15.3
CATEGORIES=	databases rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jw@innerewut.de
COMMENT=	Object-relational mapping layer for Rails MVC Framework

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-1.4.2.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	NATIVE_MYSQL "Use native MySQL bindings" Off\
		NATIVE_POSTGRESQL "Use native PostgreSQL bindings" Off\
		NATIVE_SQLITE3 "Use native SQLite3 bindings" Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>

.if defined(WITH_NATIVE_MYSQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql
.endif

.if defined(WITH_NATIVE_POSTGRESQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/postgres.so:${PORTSDIR}/databases/ruby-postgres
.endif

.if defined(WITH_NATIVE_SQLITE3)
RUN_DEPENDS+=	rubygem-sqlite3>=1.2.1:${PORTSDIR}/databases/rubygem-sqlite3
.endif

.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
