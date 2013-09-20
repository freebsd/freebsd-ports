# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	p7zip
PORTVERSION=	9.20.1
CATEGORIES=	archivers
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}_src_all

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	File archiver with high compression ratio

OPTIONS_DEFINE=        MINIMAL MODULES
OPTIONS_DEFAULT=       MODULES

MINIMAL_DESC=  Support only .7z file format
MODULES_DESC=  Build modules

NO_STAGE=	yes
USE_BZIP2=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMINIMAL}
MAN1=		7zr.1
MLINKS=		7zr.1 7z.1
PLIST_SUB=	MODULES="@comment "
ALL_TARGET=	7zr
7ZBIN=		7zr
PLIST_FILES=	bin/7zr \
		bin/7z
.else
MAN1=		7z.1 7za.1 7zr.1 p7zip.1
DLLDIR=		${PREFIX}/libexec/p7zip
ALL_TARGET=	7za 7zr sfx
7ZBIN=		7za 7zr 7zCon.sfx
PLIST_FILES=	bin/7z \
		bin/7za \
		bin/7zr \
		bin/p7zip \
		libexec/p7zip/7za \
		libexec/p7zip/7zr \
		libexec/p7zip/7zCon.sfx
.if ${PORT_OPTIONS:MMODULES}
ALL_TARGET=	7z 7za 7zr Client7z sfx
7ZBIN=		7z 7za 7zr Client7z 7zCon.sfx
PLIST_DIRS+=	libexec/p7zip/Codecs
PLIST_FILES+=	libexec/p7zip/7z \
		libexec/p7zip/7z.so \
		libexec/p7zip/Client7z \
		libexec/p7zip/Codecs/Rar29.so
.endif
PLIST_DIRS+=	libexec/p7zip
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${SED} -e 's!-O!${CFLAGS}!' \
	       -e 's!g\+\+!${CXX}!' \
	       -e 's!gcc!${CC}!' \
	       -e 's/-D_LARGEFILE_SOURCE//' \
	       -e 's/-D_FILE_OFFSET_BITS=64//' \
	       ${WRKSRC}/makefile.freebsd6 > ${WRKSRC}/makefile.machine
	${REINPLACE_CMD} -e 's|{DEST_SHARE_DOC}|${DOCSDIR}|' \
		${WRKSRC}/man1/*
	${MV} ${WRKSRC}/README ${WRKSRC}/DOCS/readme.unix
	${MV} ${WRKSRC}/contrib/gzip-like_CLI_wrapper_for_7z/man1/p7zip.1 ${WRKSRC}/man1/

do-install:
.if defined(WITH_MINIMAL)
	cd ${WRKSRC}/bin/&&${INSTALL_PROGRAM} ${7ZBIN} ${PREFIX}/bin/
	${LN} -sf ${PREFIX}/bin/7zr ${PREFIX}/bin/7z
.else
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
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/DOCS/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
	@cd ${WRKSRC}/man1/&&${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
