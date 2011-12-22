# New ports collection makefile for:   paq
# Date created:                5 April 2007
# Whom:                        bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	paq
PORTVERSION=	20111221
CATEGORIES=	archivers
MASTER_SITES=	http://mattmahoney.net/dc/ LOCAL/bf/paq/
DISTFILES=	libzpaq401.zip wbpe110.zip zpaq403.zip zpipe.201.zip
.if !defined(NOPORTDATA) || make(makesum)
DISTFILES+=	bmp_j4a.zip bwt.1.zip bwt_j3.zip bwt_slowmode1.zip \
		calgarytest.zpaq exe_j1.zip fast.cfg jpg_test2.zip max.cfg \
		mid.cfg min.zip zpsfx.100.zip
.endif
.if !defined(NOPORTDOCS) || make(makesum)
DISTFILES+=	zpaq1.pdf
.endif
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:M*.zip}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A family of archivers with extremely high compression ratios

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

EXTRACT_AFTER_ARGS=	-x *.bat *.exe readme.txt -d ${WRKDIR}
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

USE_DOS2UNIX=	yes
USE_PERL5_BUILD=	yes

SUB_FILES=	pkg-message

MAN1=	zpaq.1
MAN3=	libzpaq.3

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if !defined(WITHOUT_OPENMP) && empty(CXX:M*clang*)
PTHREAD_CFLAGS+=	-fopenmp
.endif

.if ${ARCH} == "amd64" || ( ${ARCH} == "i386" && !empty(MACHINE_CPU:Msse2) )
ZPAQFLAGS=	-msse2
.else
ZPAQFLAGS=	-DNOJIT
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	libzpaq.cpp wbpe.cpp zpaq.cpp zpaq1.pdf zpipe.cpp
.endif

.if !defined(NOPORTDATA)
.if !defined(NOPORTDOCS)
PORTDOCS+=	bwt_.cpp bwtpre.cpp bwtrle.cpp divsufsort.c divsufsort.h \
		exe_jo.cpp jpeg_jo.cpp lzppre.cpp readme_bwt.txt \
		readme_bwt_j3.txt readme_exe_j1.txt zpsfx.cpp
READMES+=	bwt_j3 exe_j1
EXTRA_PATCHES +=	${FILESDIR}/patch_zpsfx.cpp
.endif
WDATA=	bmp_j4.cfg bwt_j3.cfg bwt_slowmode1_1GB_block.cfg \
	bwt_slowmode1_256MB_block.cfg bwt_slowmode1_4MB_block.cfg \
	bwt1.cfg bwt2.cfg bwtrle1.cfg bwtrle2.cfg colorpre.cfg \
	exe_j1.cfg jpg_test2.cfg min.cfg zpsfx.tag
DDATA=	fast.cfg max.cfg mid.cfg
PORTDATA=	${WDATA} ${DDATA} zpsfx
.endif

.if !defined(NOPORTDOCS)
post-extract:
.for r in ${READMES}
	@${UNZIP_CMD} -pq  ${_DISTDIR}/${r}.zip readme.txt > ${WRKSRC}/readme_${r:R}.txt
.endfor

.endif

post-patch:
.if !defined(NOPORTDATA)
	@${REINPLACE_CMD} -e 's|c:\\res\\zpaq\\||' ${WRKSRC}/bwt[12].cfg \
		${WRKSRC}/bwtrle[12].cfg

.endif

do-build:
.if !defined(NOPORTDATA)
	@cd ${WRKSRC}; for prog in bwt_ bwtpre exe_jo jpeg_jo lzppre; do \
	${CXX} ${CXXFLAGS} -o $${prog} $${prog}.cpp; done; \
	${CXX} ${CXXFLAGS} -o bwtrle bwtrle.cpp divsufsort.c; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} -o zpsfx zpsfx.cpp libzpaq.cpp
.endif
	@cd ${WRKSRC}; \
	${CXX} ${CXXFLAGS} -o wbpe wbpe.cpp; \
	${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} ${ZPAQFLAGS} \
	 -o zpaq zpaq.cpp libzpaq.cpp divsufsort.c ${LDFLAGS} ${PTHREAD_LIBS}; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} -o zpipe zpipe.cpp libzpaq.cpp; \
	for page in ${MAN1} ${MAN3}; \
	do pod2man $${page}.pod > $${page}; done

do-install:
	@${MKDIR} ${PREFIX}/bin ${PREFIX}/include ${MANPREFIX}/man/man1 \
	${MANPREFIX}/man/man3
.for prog in wbpe zpaq zpipe
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${INSTALL_DATA} ${WRKSRC}/libzpaq.h ${PREFIX}/include
.for page in ${MAN1} ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/${page} ${MANPREFIX}/man/man${page:E}
.endfor
.if !defined(NOPORTDATA)
.for prog in bwt_ bwtpre bwtrle exe_jo jpeg_jo lzppre
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${WDATA} ${DATADIR}; \
	${INSTALL_LIB} zpsfx ${DATADIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${DDATA} ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS:Nzpaq1.pdf} ${DOCSDIR}
	@${INSTALL_DATA} ${_DISTDIR}/zpaq1.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

check regression-test test: build
	${WRKSRC}/zpaq l ${_DISTDIR}/calgarytest.zpaq

.include <bsd.port.post.mk>
