# New ports collection makefile for:	p7zip
# Date created:			Sun Jul 18 15:07:26 CEST 2004
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	p7zip
PORTVERSION=	9.04
CATEGORIES=	archivers
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}_src_all

MAINTAINER=	nox@FreeBSD.org
COMMENT=	File archiver with high compression ratio

USE_BZIP2=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAN1=		7z.1 7za.1 7zr.1 p7zip.1
MAKE_JOBS_UNSAFE=	yes

DLLDIR=		${PREFIX}/libexec/p7zip
PLIST_SUB=	MODULES=""
ALL_TARGET=	7z 7za 7zr Client7z sfx
7ZBIN=		7z 7za 7zr Client7z 7zCon.sfx
.if defined(WITHOUT_MODULES)
PLIST_SUB=	MODULES="@comment "
ALL_TARGET=	7za 7zr sfx
7ZBIN=		7za 7zr 7zCon.sfx
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${SED} -e 's!-O!${CFLAGS} ${PTHREAD_CFLAGS}!' \
	       -e 's!g\+\+!${CXX}!' \
	       -e 's!gcc!${CC}!' \
	       -e '/LITTLE_ENDIAN/d' \
	       -e 's/-D_LARGEFILE_SOURCE//' \
	       -e 's/-D_FILE_OFFSET_BITS=64//' \
	       -e 's/-lc_r/${PTHREAD_LIBS}/' \
	       ${WRKSRC}/makefile.freebsd > ${WRKSRC}/makefile.machine
	${REINPLACE_CMD} -e 's|/usr/share/doc/p7zip/DOCS|${DOCSDIR}|' \
		${WRKSRC}/man1/*
	${MV} ${WRKSRC}/README ${WRKSRC}/DOCS/readme.unix
	${MV} ${WRKSRC}/contrib/gzip-like_CLI_wrapper_for_7z/man1/p7zip.1 ${WRKSRC}/man1/

do-install:
	${INSTALL} -d ${DLLDIR}/
	cd ${WRKSRC}/bin/&&${INSTALL_PROGRAM} ${7ZBIN} ${DLLDIR}/
	${INSTALL_SCRIPT} ${FILESDIR}/7z ${PREFIX}/bin/
	${LN} -sf 7z ${PREFIX}/bin/7za
	${LN} -sf 7z ${PREFIX}/bin/7zr
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/gzip-like_CLI_wrapper_for_7z/p7zip ${PREFIX}/bin/
.if !defined(WITHOUT_MODULES)
	${INSTALL} -d ${DLLDIR}/Codecs/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Codecs/Rar29.so ${DLLDIR}/Codecs/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7z.so ${DLLDIR}/
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/DOCS/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
	@cd ${WRKSRC}/man1/&&${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
