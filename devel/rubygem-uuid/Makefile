# New ports collection makefile for:	rubygem-uuid
# Date created:		06 Nov 2008
# Whom:			Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	2.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RF/reliable-msg

MAINTAINER=	wenheping@gmail.com
COMMENT=	UUID Generator for Ruby

BUILD_DEPENDS=	rubygem-macaddr>=1.0.0:${PORTSDIR}/net/rubygem-macaddr
RUN_DEPENDS=	rubygem-macaddr>=1.0.0:${PORTSDIR}/net/rubygem-macaddr

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
