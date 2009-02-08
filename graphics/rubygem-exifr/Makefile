# Ports collection makefile for:	rubygem-exifr
# Date created:				4 October 2008
# Whom:					stas
#
# $FreeBSD$

PORTNAME=	exifr
PORTVERSION=	0.10.7
PORTREVISION=	0
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A pure-ruby EXIF reader

USE_RUBY=	yes
USE_RUBYGEMS=	yes

post-install:
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | \
		${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | \
		${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
