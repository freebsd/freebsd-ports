# ex:ts=8
# Ports collection makefile for:	rubygem-scruffy
# Date created:			Jan 7, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scruffy
PORTVERSION=	0.2.5
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Beautiful Graphs for Ruby

RUN_DEPENDS=	rubygem-builder>=2.0.0:${PORTSDIR}/devel/rubygem-builder

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST= yes

update-plist:
	@${RM} -f ${PLIST}
	@${ECHO} "%%GEM_SPEC%%" >> ${PLIST}
	@${ECHO} "%%GEM_CACHE%%" >> ${PLIST}
	@${FIND} ${LOCALBASE}/${GEM_LIB_DIR} -type f | ${SORT} | ${SED} -e \
		's,^${LOCALBASE}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> ${PLIST}
	@${FIND} ${LOCALBASE}/${GEM_LIB_DIR} -type d | ${SORT} -r | ${SED} -e \
		's,^${LOCALBASE}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> ${PLIST}
	@${FIND} ${LOCALBASE}/${GEM_DOC_DIR} -type f | ${SORT} | ${SED} -e \
		's,^${LOCALBASE}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> ${PLIST}
	@${FIND} ${LOCALBASE}/${GEM_DOC_DIR} -type d | ${SORT} -r | ${SED} -e \
		's,^${LOCALBASE}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> ${PLIST}

.include <bsd.port.mk>
