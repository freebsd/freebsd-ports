# New ports collection makefile for:	seri font collection
# Version required:	none
# Date created:		Fri Mar 27 17:26:42 KST 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1998/05/05 14:21:40 kuriyama Exp $
#

DISTNAME=	ko-kaistfonts-ksc-1.0
CATEGORIES=	korean x11
MASTER_SITES=	ftp://sensor.kaist.ac.kr/pub/fonts/newones/
DISTFILES=	kaist-newmj18.bdf.gz ks_philgi16.bdf.gz \
		kaist-newmj16.bdf.gz ks_iyagi16.bdf.gz

MAINTAINER=	junker@jazz.snu.ac.kr

USE_X_PREFIX=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV=	DISTDIR=${DISTDIR} DISTFILES="${DISTFILES}"

do-extract:
	@rm -fr ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	for file in ${DISTFILES}; do \
		${GUNZIP_CMD} -c < ${_DISTDIR}/$$file > `echo $$file | ${SED} -e 's/\.Z//' -e 's/\.gz//'`; \
	done

.include <bsd.port.mk>
