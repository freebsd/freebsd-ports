# New ports collection makefile for:	p7zip
# Date created:			Sun Jul 18 15:07:26 CEST 2004
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	p7zip
PORTVERSION=	4.14
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	p7zip
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Command line versions of 7-zip

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PORTDOCS=	*

DLLDIR=		${PREFIX}/libexec/p7zip
7ZBIN=		7za 7zCon.sfx

.if defined(WITHOUT_MODULES)
PLIST_SUB=	MODULES="@comment "
ALL_TARGET=	7za sfx
.else
PLIST_SUB=	MODULES=""
ALL_TARGET=	all2
7ZBIN+=		7z
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
IGNORE=		requires wchar functions (mbrtowc(3) etc.) for compilation
.endif

post-patch:
	${SED} -e 's/-O2/${CFLAGS} ${PTHREAD_CFLAGS}/' \
	       -e 's/g\+\+/${CXX}/' \
	       -e 's/gcc/${CC}/' \
	       -e '/LITTLE_ENDIAN/d' \
	       -e 's/-lc_r/${PTHREAD_LIBS}/' \
	       ${WRKSRC}/makefile.freebsd_x86 > ${WRKSRC}/makefile.machine

do-install:
	${MKDIR} ${DLLDIR}
.for f in ${7ZBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${DLLDIR}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/7z ${PREFIX}/bin
	${LN} -sf 7z ${PREFIX}/bin/7za
.if !defined(WITHOUT_MODULES)
.for f in Codecs Formats
	${MKDIR} ${DLLDIR}/${f}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f}/* ${DLLDIR}/${f}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${PAX} -rw -s,${WRKSRC}/DOCS,, ${WRKSRC}/DOCS ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} 755
	${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
