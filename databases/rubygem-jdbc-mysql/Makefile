# Ports collection makefile for:	rubygem-jdbc-mysql
# Date created:				22 July 2008
# Whom:					Alexander Logvinov <ports@logvinov,com>
#
# $FreeBSD$

PORTNAME=	jdbc-mysql
PORTVERSION=	5.0.4
CATEGORIES=	databases rubygems java
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	jruby-extras

MAINTAINER=	ports@logvinov.com
COMMENT=	MySQL JDBC driver for JRuby

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby

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
