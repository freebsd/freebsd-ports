# Ports collection makefile for:	rubygem-rparsec
# Date created:				24 September 2008
# Whom:					stas
#
# $FreeBSD$

PORTNAME=	rparsec
PORTVERSION=	1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Recursive descent parser combinator framework for Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes

post-install:
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
