# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.5.1/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vega Strike data files

USE_BZIP2=	yes
NO_BUILD=	yes

MANUAL_PACKAGE_BUILD=huge

do-extract:
	${MKDIR} ${WRKDIR}
	# Will extract directly into ${STAGEDIR}${DATADIR:H}

do-install:
	${RM} -rf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR:H}
	${TAR} -C ${STAGEDIR}${DATADIR:H} -xvf ${_DISTDIR}/${DISTFILES} \
	    --exclude Makefile.am --no-same-owner 2>&1 | \
		${AWK} ' \
		    BEGIN { dirn = 0 ; print "@cwd ${DATADIR}" } \
		    { sub("^x [^/]*/", "") } \
		    /\/$$/ { sub("/$$", ""); dirs[dirn++] = $$0 ; next } \
		    !/^$$/ { print $$0 } \
		    END {while (dirn--) print "@dirrm " dirs[dirn]; \
			print "@cwd"; print "@dirrm ${DATADIR_REL}" } \
		' >> ${TMPPLIST}
	${MV} ${STAGEDIR}${DATADIR:H}/vegastrike-data-${PORTVERSION} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
