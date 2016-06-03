# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcad-partslib
PORTVERSION=	2.1.2.8.1
PORTREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	ftp://www.ribbonsoft.com/archives/partlibrary/
DISTNAME=	partlibrary-${PORTVERSION:S/.1$/-1/}
EXTRACT_ONLY=

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

WRKSRC=		${WRKDIR}/partlibrary-${PORTVERSION:S/.1$/-1/}
DATADIR=	share/qcad/library

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/${DATADIR}
	${TAR} -C ${STAGEDIR}/${PREFIX}/${DATADIR} --exclude CVS --unlink --strip-components 1 \
		-xvof ${_DISTDIR}${DISTFILES} 2>&1 | ${AWK} '	\
			$$1 != "x" {				\
				print "ERROR: " $$0 > "/dev/stderr"; exit 1	\
			} {					\
				if (sub("/$$", "", $$2))	\
					next ;			\
				else if ($$2 != "")		\
					print "${DATADIR}/" $$2;	\
				next	\
			}' >> ${TMPPLIST}

.include <bsd.port.mk>
