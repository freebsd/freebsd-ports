# New ports collection makefile for:	rubygem-jpmobile
# Date created:		2008-02-06
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	jpmobile
PORTVERSION=	0.0.2
CATEGORIES=	japanese www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tota@rtfm.jp
COMMENT=	A Rails plugin for Japanese mobile-phones

BUILD_DEPENDS=	rubygem-actionpack>=1.12.5:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-hpricot>=0.4:${PORTSDIR}/www/rubygem-hpricot
RUN_DEPENDS=	rubygem-actionpack>=1.12.5:${PORTSDIR}/www/rubygem-actionpack \
		rubygem-hpricot>=0.4:${PORTSDIR}/www/rubygem-hpricot

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
