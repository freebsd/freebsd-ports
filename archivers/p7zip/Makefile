# New ports collection makefile for:	p7zip
# Date created:			Sun Jul 18 15:07:26 CEST 2004
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	p7zip
PORTVERSION=	4.39
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src_all

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Command line versions of 7-zip

USE_BZIP2=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PORTDOCS=	*
MAN1=		7z.1 7za.1 7zr.1
MANCOMPRESSED=	no

DLLDIR=		${PREFIX}/libexec/p7zip

PLIST_SUB=	MODULES=""
ALL_TARGET=	7z 7za 7zr sfx
7ZBIN=		7z 7za 7zr 7zCon.sfx
.if defined(WITHOUT_MODULES)
PLIST_SUB=	MODULES="@comment "
ALL_TARGET=	7za 7zr sfx
7ZBIN=		7za 7zr 7zCon.sfx
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
IGNORE=		requires wchar functions (mbrtowc(3) etc.) for compilation
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${SED} -e 's/-O/${CFLAGS} ${PTHREAD_CFLAGS}/' \
	       -e 's!g\+\+!${CXX}!' \
	       -e 's!gcc!${CC}!' \
	       -e '/LITTLE_ENDIAN/d' \
	       -e 's/-D_LARGEFILE_SOURCE//' \
	       -e 's/-D_FILE_OFFSET_BITS=64//' \
	       -e 's/-lc_r/${PTHREAD_LIBS}/' \
	       ${WRKSRC}/makefile.freebsd > ${WRKSRC}/makefile.machine
	${REINPLACE_CMD} -e 's|/usr/share/doc/p7zip/DOCS|${DOCSDIR}|' \
		${WRKSRC}/man1/*

do-install:
	${INSTALL} -d ${DLLDIR}
.for f in ${7ZBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${DLLDIR}/
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/7z ${PREFIX}/bin/
	${LN} -sf 7z ${PREFIX}/bin/7za
	${LN} -sf 7z ${PREFIX}/bin/7zr
	${INSTALL_SCRIPT} ${FILESDIR}/p7zip ${PREFIX}/bin/
.if !defined(WITHOUT_MODULES)
.for f in Codecs Formats
	${INSTALL} -d ${DLLDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/bin/${f}/* ${DLLDIR}/${f}/
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${PAX} -rw -s,${WRKSRC}/DOCS,, ${WRKSRC}/DOCS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/readme.unix
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} 755
	${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man1/,} ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
