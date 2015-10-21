# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	fasta3
PORTVERSION=	36.3.8
CATEGORIES=	biology
MASTER_SITES=	http://faculty.virginia.edu/wrpearson/fasta/fasta36/
DISTNAME=	fasta-${PORTVERSION}
DIST_SUBDIR=	fasta3/2014-01-29

MAINTAINER=	wendell@bsd.com.br
COMMENT=	Collection of programs for searching DNA and protein databases

LICENSE=	Fasta
LICENSE_NAME=	Fasta program copyright W. Pearson and U.Virginia
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_CDROM=	May not be sold or incorporated into a commercial product

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

MAKEFILE=	Makefile.freebsd
MAKE_ENV=	THR_LIBS="-pthread" XDIR="${STAGEDIR}${PREFIX}/bin" \
		FASTA_HOST="$$(${UNAME} -n)"

SUB_FILES=	pkg-message

PLIST_SUB=	VER="${PORTVERSION:R:R}"

MAN1_LINKS=	fastf35.1 fasts35.1 fastm35.1 fastx35.1 fasty35.1 \
		ggsearch35.1 lalign35.1 ssearch35.1 tfasta35.1 tfastf35.1 \
		tfasts35.1 tfastx35.1 tfasty35.1 prfx35.1 prss35.1
MAN1_FILES=	fasta36.1 fastf3.1 fasts3.1 prss3.1 map_db.1 ps_lav.1
DOC_FILES=	README.versions \
		fasta_func.doc readme.* fasta.defaults \
		fasta.options fasta_versions.html changes*.html
DATA=		data/*.mat
EXAMPLES=	seq/*.aa seq/*.lc seq/*.seq seq/*.lib

post-patch:
	@${CP} ${WRKSRC}/make/${MAKEFILE} ${BUILD_WRKSRC}
	@${RM} ${WRKSRC}/bin/README

post-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} * ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/conf && ${INSTALL_DATA} fastlibs \
		${STAGEDIR}${PREFIX}/etc/fastlibs.sample)
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for data in ${DATA}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${data} ${STAGEDIR}${DATADIR})
.endfor
.for manpage in ${MAN1_FILES}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${manpage} \
		${STAGEDIR}${MAN1PREFIX}/man/man1)
.endfor
.for links in ${MAN1_LINKS}
	(${LN} -sf fasta36.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${links})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in COPYRIGHT FASTA_LIST README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
.for docfile in ${DOC_FILES}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${docfile} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in ${EXAMPLES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${ex} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
