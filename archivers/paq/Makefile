# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	paq
PORTVERSION=	20130124
CATEGORIES=	archivers
MASTER_SITES=	http://mattmahoney.net/dc/ LOCAL/bf/paq/
DISTFILES=	wbpe110.zip zpaq619.zip zpipe.201.zip
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:M*.zip}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Family of archivers with extremely high compression ratios

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

USE_DOS2UNIX=	yes
USE_ZIP=	yes

EXTRACT_AFTER_ARGS=	-x *.bat *.exe readme.txt -d ${WRKDIR}
NO_WRKSUBDIR=	yes
OPTIONS_DEFINE=	OPENMP
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ( ${ARCH} == "i386" && !empty(MACHINE_CPU:Msse2) )
ZPAQFLAGS=	-Dunix -msse2
.else
ZPAQFLAGS=	-DNOJIT
.endif

.if defined(WITH_DEBUG)
CXXFLAGS+=	-DDEBUG
.else
CXXFLAGS+=	-DNDEBUG
.endif

.if !defined(NOPORTDATA) || make(makesum)
DISTFILES+=	bmp_j4c.zip bwt.1.zip bwt_j3.zip bwt_slowmode1.zip \
		calgarytest.zpaq calgarytest2.zpaq exe_j1.zip fast.cfg \
		jpg_test2.zip lazy210.zip lz1.zip max.cfg mid.cfg min.zip \
		zpsfx.100.zip zpsfx101.cpp
.endif

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	zpaq1.pdf zpaq201.pdf
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	libzpaq.cpp wbpe.cpp zpaq.cpp zpaq1.pdf zpaq201.pdf zpipe.cpp
.endif

.if !defined(NOPORTDATA)
.if ${PORT_OPTIONS:MDOCS}
PORTDOCS+=	bwt_.cpp bwtpre.cpp bwtrle.cpp divsufsort.c divsufsort.h \
		exe_jo.cpp jpeg_jo.cpp lzpre.cpp lzppre.cpp readme_bwt.txt \
		readme_bwt_j3.txt readme_exe_j1.txt readme_lazy210.txt zpsfx.cpp
READMES+=	bwt_j3 exe_j1 lazy210
EXTRA_PATCHES+=	${FILESDIR}/patch_zpsfx.cpp
.endif
WDATA=	bmp_j4.cfg bwt_j3.cfg bwt_slowmode1_1GB_block.cfg \
	bwt_slowmode1_256MB_block.cfg bwt_slowmode1_4MB_block.cfg \
	bwt1.cfg bwt2.cfg bwtrle1.cfg bwtrle2.cfg colorpre.cfg \
	exe_j1.cfg jpg_test2.cfg lazy2.cfg lz1.cfg min.cfg zpsfx.tag
DDATA=	fast.cfg max.cfg mid.cfg
PORTDATA=	${WDATA} ${DDATA} zpsfx
.endif

.if ${PORT_OPTIONS:MOPENMP}
PTHREAD_CFLAGS+=	-fopenmp
USE_GCC=		any
.endif

post-extract:
	@${CP} ${_DISTDIR}/zpsfx101.cpp ${WRKSRC}/zpsfx.cpp
.if ${PORT_OPTIONS:MDOCS}
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
	@cd ${WRKSRC}; for prog in bwt_ bwtpre exe_jo jpeg_jo lazy2 lzpre \
	lzppre; do \
	${CXX} ${CXXFLAGS} -o $${prog} $${prog}.cpp; done; \
	${CXX} ${CXXFLAGS} -o bwtrle bwtrle.cpp divsufsort.c; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} -o zpsfx zpsfx.cpp libzpaq.cpp
.endif
	@cd ${WRKSRC}; \
	${CXX} ${CXXFLAGS} -o wbpe wbpe.cpp; \
	${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} ${ZPAQFLAGS} \
	-o zpaq zpaq.cpp libzpaq.cpp divsufsort.c ${LDFLAGS} ${PTHREAD_LIBS}; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} \
	-o zpaqd zpaqd.cpp libzpaq.cpp ${LDFLAGS}; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} -o zpipe zpipe.cpp libzpaq.cpp

do-install:
.for prog in wbpe zpaq zpaqd zpipe
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${INSTALL_DATA} ${WRKSRC}/libzpaq.h ${PREFIX}/include
.if !defined(NOPORTDATA)
.for prog in bwt_ bwtpre bwtrle exe_jo jpeg_jo lazy2 lzpre lzppre
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${WDATA} ${DATADIR}; \
	${INSTALL_LIB} zpsfx ${DATADIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${DDATA} ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS:N*.pdf} ${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS:M*.pdf} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

check regression-test test: build
	${WRKSRC}/zpaq -list ${_DISTDIR}/calgarytest.zpaq
	${WRKSRC}/zpaq -list ${_DISTDIR}/calgarytest2.zpaq

.include <bsd.port.mk>
