PORTNAME=	cfortran
PORTVERSION=	4.3
CATEGORIES=	lang
MASTER_SITES=	http://www-zeus.desy.de/~burow/cfortran/
DISTFILES=	cfortran.h \
		cfortran.html \
		cfortran.doc \
		cfortran.examples.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use powerful bridge between C and FORTRAN

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	include/cfortran.h
PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
.for dfile in ${DISTFILES}
	${CP} ${_DISTDIR}/${dfile} ${WRKSRC}
.endfor
	(cd ${WRKSRC} && ${TAR} -xf cfortran.examples.tar.gz)

do-install:
	${INSTALL_DATA} ${WRKSRC}/cfortran.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cfortran.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cfortran.doc ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/eg && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
