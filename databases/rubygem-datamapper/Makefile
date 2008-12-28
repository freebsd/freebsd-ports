# New ports collection makefile for:	rubygem-datamapper
# Date created:		28, Dec 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datamapper
PORTVERSION=	0.3.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Fast, thread-safe, object-relational mapper

BUILD_DEPENDS=	rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-validatable>0:${PORTSDIR}/devel/rubygem-validatable \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastthread>0:${PORTSDIR}/devel/rubygem-fastthread
RUN_DEPENDS=	rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-validatable>0:${PORTSDIR}/devel/rubygem-validatable \
		rubygem-json>0:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastthread>0:${PORTSDIR}/devel/rubygem-fastthread

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes

post-install:
	@${ECHO} ${GEM_CACHE} > ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
