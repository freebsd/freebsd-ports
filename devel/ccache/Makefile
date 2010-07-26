# New ports collection makefile for:	ccache
# Date created:				31/03/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	ccache
PORTVERSION=	2.4
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to minimize the compile time of C/C++ programs

GNU_CONFIGURE=	yes

MAN1=		ccache.1
PLIST_FILES=	bin/ccache

PORTDOCS=	index.html \
		ccache-man.html \
		${HOWTO}

.if !defined(WITHOUT_COMPILER_LINKS)
HOWTO=		ccache-howto-freebsd.txt
CCLINKDIR=	libexec/ccache
PLIST_DIRS=	${CCLINKDIR}
SUB_FILES=	${HOWTO} pkg-message
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_COMPILER_LINKS)
.if ${ARCH}=="i386"
CCACHE_COMPILERS+=      icc icpc
.endif
GNU_COMPILERS+=		34 42 43 44 -ooo
CCACHE_COMPILERS+=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}
.if defined(EXTRA_COMPILERS)
CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
.endif
WORLD_COMPILERS=	world-cc world-c++
PLIST_FILES+=	${CCACHE_COMPILERS:S|^|${CCLINKDIR}/|} \
		${WORLD_COMPILERS:S|^|${CCLINKDIR}/|}
SUB_FILES+=	${WORLD_COMPILERS}
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
	@${MKDIR} ${PREFIX}/${CCLINKDIR}
.for link in ${CCACHE_COMPILERS}
	${LN} -sf ${PREFIX}/bin/ccache ${PREFIX}/${CCLINKDIR}/${link}
.endfor
.for script in ${WORLD_COMPILERS}
	${INSTALL_SCRIPT} ${WRKDIR}/${script} ${PREFIX}/${CCLINKDIR}
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
