# Ports collection makefile for:	rubygem-exifr
# Date created:				4 October 2008
# Whom:					stas
#
# $FreeBSD$

PORTNAME=	exifr
PORTVERSION=	0.10.6
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A pure-ruby EXIF reader

USE_RUBY=	yes
USE_RUBYGEMS=	yes

post-install:
	cd ${PREFIX}/${GEM_LIB_DIR}/bin && \
		${PATCH} -p0 < ${FILESDIR}/exifr.patch && \
		${RM} -f ${PREFIX}/${GEM_LIB_DIR}/bin/exifr.orig
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | \
		${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},${GEM_DOC_DIR},' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | \
		${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm ${GEM_DOC_DIR},' >> ${TMPPLIST}

.include <bsd.port.mk>
