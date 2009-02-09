# New ports collection makefile for:	rubygem-lockfile
# Date created:		2009-01-25
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	lockfile
PORTVERSION=	1.4.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RF/codeforpeople

MAINTAINER=	adox@mcx2.org
COMMENT=	A ruby library for creating NFS safe lockfiles

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes

post-install:
	@${ECHO} bin/rlock >> ${TMPPLIST}
	@${ECHO} bin/rlock-${PORTVERSION} >> ${TMPPLIST}
	@${ECHO} ${GEM_CACHE} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${ECHO} ${GEM_SPEC} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm ${GEM_LIB_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
