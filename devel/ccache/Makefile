# New ports collection makefile for:	ccache
# Date created:				31/03/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	ccache
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ccache.samba.org/ftp/ccache/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A tool to minimize the compile time of C/C++ programs

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ccache.1
PLIST_FILES=	bin/ccache

PORTDOCS=	index.html \
		ccache-man.html \
		${HOWTO}

.if !defined(WITHOUT_COMPILER_LINKS)
HOWTO=		ccache-howto-freebsd.txt
PKGMESSAGE=	${WRKDIR}/pkg-message
CCLINKDIR=	libexec/ccache
PLIST_DIRS=	${CCLINKDIR}
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_COMPILER_LINKS)
GNU_COMPILERS=		295 32 33 34 35 40
CCACHE_COMPILERS=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}
.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif
.if defined(EXTRA_COMPILERS)
CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
.endif
PLIST_FILES+=	${CCACHE_COMPILERS:S|^|${CCLINKDIR}/|}
.endif

pre-everything::
.if !defined(WITHOUT_COMPILER_LINKS)
	@${ECHO_MSG} "===>  Ccache will install compiler links in ${PREFIX}/libexec/ccache"
	@${ECHO_MSG} "===>  Links that will be created are"
	@${ECHO_MSG} "===>  ${CCACHE_COMPILERS}"
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===>  You may add more by EXTRA_COMPILERS=\"Ccompiler1 C++compiler1 etc..\""
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===>  You can disable compiler links by defining"
	@${ECHO_MSG} "===>  WITHOUT_COMPILER_LINKS"
	@${ECHO_MSG} "===>"
.endif

post-extract:
.if !defined(WITHOUT_COMPILER_LINKS)
	@${SED} -e 's|%%CCACHE_COMPILERS%%|${CCACHE_COMPILERS}|; \
		s|%%PREFIX%%|${PREFIX}|; s|%%CCLINKDIR%%|${CCLINKDIR}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|; \
		s|%%ICCPREFIX%%|${LOCALBASE}/intel_cc_80/bin|' \
		${FILESDIR}/${HOWTO}.in > ${WRKDIR}/${HOWTO}
	@${SED} -e 's|%%HOWTO%%|${HOWTO}|; \
		s|%%DOCSDIR%%|${DOCSDIR}|' \
		${FILESDIR}/pkg-message.in >${PKGMESSAGE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(WITHOUT_COMPILER_LINKS)
	@${MKDIR} ${PREFIX}/${CCLINKDIR}
.for link in ${CCACHE_COMPILERS}
	${LN} -sf ${PREFIX}/bin/ccache ${PREFIX}/${CCLINKDIR}/${link}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS:S/${HOWTO}//}
	${INSTALL_DATA} ${WRKSRC}/web/${i} ${DOCSDIR}
.endfor
.if !defined(WITHOUT_COMPILER_LINKS)
	${INSTALL_DATA} ${WRKDIR}/${HOWTO} ${DOCSDIR}
.endif
.endif
.if !defined(WITHOUT_COMPILER_LINKS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
