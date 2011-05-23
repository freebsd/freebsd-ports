# New ports collection makefile for:   paq
# Date created:                5 April 2007
# Whom:                        bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	paq
PORTVERSION=	20110518
CATEGORIES=	archivers
MASTER_SITES=	http://mattmahoney.net/dc/ LOCAL/bf/paq/
DISTFILES=	libzpaq.202a.zip unzp.100.zip zp.102.zip zpaq.205.zip zpipe.201.zip
.if !defined(NOPORTDATA) || make(makesum)
DISTFILES+=	bmp_j4.zip bwt.1.zip bwt_j3.zip bwt_slowmode1.zip exe_j1.zip \
		fast.cfg jpg_test2.zip max.cfg mid.cfg min.zip zpsfx.100.zip
.endif
.if !defined(NOPORTDOCS) || make(makesum)
DISTFILES+=	zpaq1.pdf
.endif
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:M*.zip}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A family of archivers with extremely high compression ratios

EXTRACT_AFTER_ARGS=	-x *.bat *.exe readme.txt unzp zp -d ${WRKDIR}
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

USE_DOS2UNIX=	yes
USE_PERL5_BUILD=	yes

SUB_FILES=	pkg-message

MAN1=	zpaq.1
MAN3=	libzpaq.3

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

UNZPFLAGS=	-DOPT="\"${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} \
		-I${PREFIX}/include \$$1.cpp ${PREFIX}/lib/zpaq/unzp.o \
		${PREFIX}/lib/zpaq/libzpaq.o ${PTHREAD_LIBS} -o \$$1.exe\""
ZPAQFLAGS=	-DOPT="\"${CXX} ${CXXFLAGS} -I${PREFIX}/include zpaqopt.cpp \
		${PREFIX}/lib/zpaq/zpaq.o ${PREFIX}/lib/zpaq/libzpaq.o \
		-o zpaqopt.exe\""

.if !defined(NOPORTDOCS)
PORTDOCS=	libzpaq.cpp libzpaqo.cpp unzp.cpp zp.cpp zpaq.cpp \
		zpaq1.pdf zpipe.cpp
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

.if !defined(NOPORTDATA)
post-patch:
	@${REINPLACE_CMD} -e 's|c:\\res\\zpaq\\||' ${WRKSRC}/bwt[12].cfg \
		${WRKSRC}/bwtrle[12].cfg

.endif

do-build:
.if !defined(NOPORTDATA)
	@(cd ${WRKSRC}; for prog in bwt_ bwtpre exe_jo jpeg_jo lzppre; do \
	${CXX} ${CXXFLAGS} $${prog}.cpp -o $${prog}; done; \
	${CXX} ${CXXFLAGS} bwtrle.cpp divsufsort.c -o bwtrle; \
	${CXX} ${CXXFLAGS} zpsfx.cpp libzpaq.cpp libzpaqo.cpp -o zpsfx)
.endif
	@(cd ${WRKSRC}; \
	${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} ${UNZPFLAGS} \
	unzp.cpp libzpaq.cpp ${PTHREAD_LIBS} -o unzp; \
	${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} zp.cpp libzpaq.cpp divsufsort.c \
	${PTHREAD_LIBS} -o zp; \
	${CXX} ${CXXFLAGS} ${ZPAQFLAGS} zpaq.cpp libzpaq.cpp libzpaqo.cpp \
	-o zpaq; \
	${CXX} ${CXXFLAGS} zpipe.cpp libzpaq.cpp libzpaqo.cpp -o zpipe; \
	${CXX} ${CXXFLAGS} ${PTHREAD_CFLAGS} -c libzpaq.cpp unzp.cpp; \
	${CXX} ${CXXFLAGS} -c zpaq.cpp; \
	for page in ${MAN1} ${MAN3}; \
	do pod2man $${page}.pod > $${page}; done)

do-install:
	@${MKDIR} ${PREFIX}/bin ${PREFIX}/include ${PREFIX}/lib/zpaq \
	${MANPREFIX}/man/man1 ${MANPREFIX}/man/man3
.for prog in unzp zp zpaq zpipe
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${INSTALL_DATA} ${WRKSRC}/libzpaq.h ${PREFIX}/include
.for obj in  libzpaq.o unzp.o zpaq.o
	@${INSTALL_DATA} ${WRKSRC}/${obj} ${PREFIX}/lib/zpaq
.endfor
.for page in ${MAN1} ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/${page} ${MANPREFIX}/man/man${page:E}
.endfor
.if !defined(NOPORTDATA)
.for prog in bwt_ bwtpre bwtrle exe_jo jpeg_jo lzppre
	@${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${WDATA} ${DATADIR}; \
	${INSTALL_LIB} zpsfx ${DATADIR})
	@(cd ${_DISTDIR}; ${INSTALL_DATA} ${DDATA} ${DATADIR})
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS:Nzpaq1.pdf} ${DOCSDIR})
	@${INSTALL_DATA} ${_DISTDIR}/zpaq1.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
