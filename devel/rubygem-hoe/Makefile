# Ports collection makefile for:	rubygem-hoe
# Date created:				5 December 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	hoe
PORTVERSION=	1.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	jw@innerewut.de
COMMENT=	A simple rake/rubygems helper for project Rakefiles

BUILD_DEPENDS=	rubyforge:${PORTSDIR}/devel/rubygem-rubyforge
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes

post-install:
	@${ECHO} bin/sow > ${TMPPLIST}
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
