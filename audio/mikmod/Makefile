# ports collection makefile for:   mikmod304
# Version required:    3.0.4
# Date created:        16 November 1998
# Whom:                yoshiaki Uchikawa
#
# $Id$
#

DISTNAME=	mikmod-3.0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.multimania.com/miodrag/mikmod/

MAINTAINER=	yoshiaki@kt.rim.or.jp

pre-patch:
	@(cd ${WRKSRC} ;\
	 ${CP} ${FILESDIR}/config.sh ${WRKSRC}; \
	 ${PATCH} ${PATCH_ARGS} -p1  < ${FILESDIR}/patch-s3mvolslides.diff )

pre-build:
	(cd ${WRKSRC}; ${SH} config.sh )

do-install:
	( cd ${WRKSRC}; ${INSTALL_PROGRAM} mikmod ${PREFIX}/bin )
	( cd ${WRKSRC}/playercode ; ${INSTALL_DATA} libmikmod.a ${PREFIX}/lib )
	( cd ${WRKSRC}/mmio ; ${INSTALL_DATA} libmmio.a ${PREFIX}/lib )
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mikmod
.for f in  AUTHORS COPYING.LIB ChangeLog README*
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/$f ${PREFIX}/share/doc/mikmod
.endfor
.endif

post-install:
	@strip ${PREFIX}/bin/mikmod

.include <bsd.port.mk>
