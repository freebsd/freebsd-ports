# Ports collection makefile for:	rubygem-activerecord-jdbcmysql-adapter
# Date created:				22 July 2008
# Whom:					Alexander Logvinov <ports@logvinov,com>
#
# $FreeBSD$

PORTNAME=	activerecord-jdbcmysql-adapter
PORTVERSION=	0.8.2
CATEGORIES=	databases rubygems java
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	jruby-extras

MAINTAINER=	ports@logvinov.com
COMMENT=	An ActiveRecord driver for MySQL using JDBC running under JRuby

BUILD_DEPENDS=	rubygem-jdbc-mysql>=5.0.4:${PORTSDIR}/databases/rubygem-jdbc-mysql \
		rubygem-activerecord-jdbc-adapter>=0.8.2:${PORTSDIR}/databases/rubygem-activerecord-jdbc-adapter
RUN_DEPENDS=	rubygem-jdbc-mysql>=5.0.4:${PORTSDIR}/databases/rubygem-jdbc-mysql \
		rubygem-activerecord-jdbc-adapter>=0.8.2:${PORTSDIR}/databases/rubygem-activerecord-jdbc-adapter \
		jruby:${PORTSDIR}/lang/jruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes

post-install:
	@${ECHO} ${GEM_CACHE} > ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
