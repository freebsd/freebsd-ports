# Ports collection makefile for:	rubygem-mocha
# Date created:				Apr 21 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mocha
PORTVERSION=	0.5.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A library for mocking and stubbing syntax like JMock, and SchMock

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

post-install:
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
