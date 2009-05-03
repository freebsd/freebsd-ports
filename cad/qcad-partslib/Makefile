# New ports collection makefile for:	qcad-partslib
# Date created:		28 Mar 2004
# Whom:			Michael Reifenberger <mr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad-partslib
PORTVERSION=	2.1.2.8.1
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	ftp://www.ribbonsoft.com/archives/partlibrary/
DISTNAME=	partlibrary-${PORTVERSION:S/.1$/-1/}
EXTRACT_ONLY=

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

WRKSRC=		${WRKDIR}/partlibrary-${PORTVERSION:S/.1$/-1/}
DATADIR=	share/qcad/library

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/${DATADIR}
	${TAR} -C ${PREFIX}/${DATADIR} --exclude CVS --unlink --strip-components 1	\
		-xovf ${_DISTDIR}${DISTFILES} 2>&1 | ${AWK} '	\
			$$1 != "x" {				\
				print "ERROR: " $$0 > "/dev/stderr"; exit 1	\
			} {					\
				if (sub("/$$", "", $$2))	\
					dirs[$$2] = 1;		\
				else if ($$2 != "")		\
					print "${DATADIR}/" $$2;	\
				next	\
			} END {					\
				for (d in dirs)			\
					print "@dirrm ${DATADIR}/" d |"sort -r"	\
			}' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrmtry ${DATADIR:H}' >> ${TMPPLIST}

.include <bsd.port.mk>
