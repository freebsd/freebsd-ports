# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	p7zip
PORTVERSION=	15.14
CATEGORIES=	archivers
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}_src_all

MAINTAINER=	rakuco@FreeBSD.org
COMMENT?=	File archiver with high compression ratio

LICENSE?=	LGPL21

ALL_TARGET?=	all3
USES=		cpe tar:bzip2
CPE_VENDOR=	7-zip
MAKEFILE=	makefile
MAKE_ARGS=	OPTFLAGS="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_ia64=	-fPIC
CFLAGS_powerpc=	-fPIC
CFLAGS_sparc64=	-fPIC

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	${SED} -e 's!g\+\+!${CXX}!' \
	       -e 's!gcc!${CC}!' \
	       -e 's/ -s //' \
	       -e 's/-D_LARGEFILE_SOURCE//' \
	       -e 's/-D_FILE_OFFSET_BITS=64//' \
	       ${WRKSRC}/makefile.freebsd6+ > ${WRKSRC}/makefile.machine
	${REINPLACE_CMD} -e 's|{DEST_SHARE_DOC}|${DOCSDIR}|' \
		${WRKSRC}/man1/*
	${MV} ${WRKSRC}/README ${WRKSRC}/DOC/readme.unix

.if ! defined(PKGNAMESUFFIX)
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/p7zip
.for BINARY in 7z 7za 7zr 7zCon.sfx
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINARY} ${STAGEDIR}${PREFIX}/libexec/p7zip
.endfor
	${INSTALL_LIB} ${WRKSRC}/bin/7z.so ${STAGEDIR}${PREFIX}/libexec/p7zip

	${INSTALL_SCRIPT} ${FILESDIR}/7z ${STAGEDIR}${PREFIX}/bin
	${LN} -sf 7z ${STAGEDIR}${PREFIX}/bin/7za
	${LN} -sf 7z ${STAGEDIR}${PREFIX}/bin/7zr

	(cd ${WRKSRC}/man1 && \
		${INSTALL_MAN} 7z*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1)

do-install-DOCS-on:
	(cd ${WRKSRC}/DOC && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
