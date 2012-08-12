# New ports collection makefile for:	ccache
# Date created:				31/03/2002
# Whom:					Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	ccache
PORTVERSION=	3.1.8
CATEGORIES=	devel
MASTER_SITES=	http://www.samba.org/ftp/ccache/ CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

HOWTO=		ccache-howto-freebsd.txt
CCLINKDIR=	libexec/ccache
SUB_FILES=	${HOWTO} world-ccache pkg-message ccache-update-links.sh

MAN1=		ccache.1

PORTDOCS=	ccache-howto-freebsd.txt MANUAL.html

OPTIONS=	CLANGLINK	"Create clang compiler links if clang is installed" off \
		LLVMLINK	"Create llvm compiler links if llvm is installed" off \
		STATIC		"Statically build ccache" off

.include <bsd.port.pre.mk>

PLIST_SUB+=	CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		34 42 43 44 45 46 47 48
CCACHE_COMPILERS+=	cc c++ gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}

.if defined(WITH_CLANGLINK)
CCACHE_COMPILERS+=	clang clang++
.endif

.if defined(WITH_LLVMLINK)
CCACHE_COMPILERS+=	llvm-gcc llvm-c++ llvm-g++
.endif

.if defined(WITH_STATIC)
LDFLAGS+=		"--static"
.endif

CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
SUB_LIST+=	CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
		CCLINKDIR="${CCLINKDIR}" \
		ICCPREFIX="${LOCALBASE}/intel_cc_80/bin" \
		HOWTO="${HOWTO}"

post-build:
.if !defined(TINDERBOX)
	@${MKDIR} ${WRKDIR}/tb/opt
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKDIR}/tb/opt
.for l in ${CCACHE_COMPILERS}
	@${LN} -sf ${PORTNAME} ${WRKDIR}/tb/opt/${l}
.endfor
	@${TAR} -C ${WRKDIR}/tb -cpf ${WRKSRC}/${PORTNAME}.tar opt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${PREFIX}/bin/ccache-update-links
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.tar ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${HOWTO} ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD} "Creating compiler links..."
	@${PREFIX}/bin/ccache-update-links -v
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_CLANGLINK)
	@${CAT} ${FILESDIR}/pkg-message-clang
.endif

.include <bsd.port.post.mk>
