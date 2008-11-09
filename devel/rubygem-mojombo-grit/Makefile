# Ports collection makefile for:	rubygem-mojombo-grit
# Date created:				2008-11-05
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$

PORTNAME=	mojombo-grit
PORTVERSION=	0.9.4
CATEGORIES=	devel rubygems
MASTER_SITES=	http://gems.github.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	gems

MAINTAINER=	daniel@roe.ch
COMMENT=	An object-oriented ruby library to access git repositories

BUILD_DEPENDS=	rubygem-open4>=0.0.0:${PORTSDIR}/devel/rubygem-open4 \
		rubygem-diff-lcs>=0.0.0:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-mime-types>=0.0.0:${PORTSDIR}/misc/rubygem-mime-types
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes

post-install:
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
