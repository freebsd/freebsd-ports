# New ports collection makefile for:	rubygem-main
# Date created:		07, Nov 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	main
PORTVERSION=	2.8.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RF/codeforpeople

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Class Factory and Dsl for Generating Command Line Programs

BUILD_DEPENDS=	rubygem-fattr>=1.0.3:${PORTSDIR}/devel/rubygem-fattr \
		rubygem-arrayfields>=4.5.0:${PORTSDIR}/devel/rubygem-arrayfields
RUN_DEPENDS=	rubygem-fattr>=1.0.3:${PORTSDIR}/devel/rubygem-fattr \
		rubygem-arrayfields>=4.5.0:${PORTSDIR}/devel/rubygem-arrayfields

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
