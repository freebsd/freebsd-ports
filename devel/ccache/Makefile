# New ports collection makefile for:	ccache
# Date created:				31/03/2002
# Whom:					Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	ccache
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/ CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

GNU_CONFIGURE=	yes

MAN1=		ccache.1
PLIST_FILES=	bin/ccache

PORTDOCS=	*

.if !defined(WITHOUT_COMPILER_LINKS)
HOWTO=		ccache-howto-freebsd.txt
CCLINKDIR=	libexec/ccache
PLIST_DIRS=	${CCLINKDIR}/world ${CCLINKDIR}
SUB_FILES=	${HOWTO} pkg-message
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_COMPILER_LINKS)
.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif
GNU_COMPILERS+=		34 42 43 44 45 46
CCACHE_COMPILERS+=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}
CCACHE_COMPILERS+=	clang clang++ llvm-gcc llvm-c++ llvm-g++
.if defined(EXTRA_COMPILERS)
CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
.endif
PLIST_FILES+=	${CCACHE_COMPILERS:S|^|${CCLINKDIR}/|} \
		${CCACHE_COMPILERS:S|^|${CCLINKDIR}/world/|} \
		${CCLINKDIR}/world/ccache
SUB_FILES+=	world-ccache
SUB_LIST+=	CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
		CCLINKDIR="${CCLINKDIR}" \
		ICCPREFIX="${LOCALBASE}/intel_cc_80/bin" \
		HOWTO="${HOWTO}"
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(WITHOUT_COMPILER_LINKS)
	@${MKDIR} ${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache ${PREFIX}/${CCLINKDIR}/world/ccache
.for link in ${CCACHE_COMPILERS}
	${LN} -sf ${PREFIX}/bin/ccache ${PREFIX}/${CCLINKDIR}/${link}
	${LN} -sf ccache ${PREFIX}/${CCLINKDIR}/world/${link}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.html ${DOCSDIR}
.if !defined(WITHOUT_COMPILER_LINKS)
	${INSTALL_DATA} ${WRKDIR}/${HOWTO} ${DOCSDIR}
.endif
.endif
.if !defined(WITHOUT_COMPILER_LINKS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
