# Ports collection makefile for:	rubygem-warbler
# Date created:				23 July 2008
# Whom:					Alexander Logvinov <ports@logvinov,com>
#
# $FreeBSD$

PORTNAME=	warbler
PORTVERSION=	0.9.10
CATEGORIES=	devel rubygems java
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	caldersphere

MAINTAINER=	ports@logvinov.com
COMMENT=	A constructor of .war files of Rails applications

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

post-install:
	@${ECHO} bin/warble > ${TMPPLIST}
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
