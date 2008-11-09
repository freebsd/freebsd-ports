# Ports collection makefile for:	rubygem-git
# Date created:				2008-11-09
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$

PORTNAME=	git
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	gems

MAINTAINER=	daniel@roe.ch
COMMENT=	A ruby wrapper library around git(1)

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

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
