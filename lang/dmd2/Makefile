# New ports collection makefile for:	dmd2
# Date created:				November 29 2010
# Whom:					Ruben <chromium@hybridsource.org>
#
# $FreeBSD$
#

PORTNAME=	dmd
PKGNAMESUFFIX=	2
PORTVERSION=	2.061
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
DISTNAME=	dmd.${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	D 2.0 compiler, not officially validated for FreeBSD

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	posix.mak
MAN1=		dmd2.1
MAN5=		dmd2.conf.5
EXAMPLESDIR=	${PREFIX}/share/examples/dmd2
DOCSDIR=	${PREFIX}/share/doc/dmd2
PORTDOCS=	*.txt druntime/ html/ phobos/
WRKSRC=		${WRKDIR}/dmd2/src/${PORTNAME}
LICENSE_COMB=	multi
LICENSE=	ART10 DMD BSL
LICENSE_NAME_DMD=	Digital Mars license
LICENSE_FILE_DMD=	${WRKSRC}/backendlicense.txt
LICENSE_PERMS_DMD=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile
.endif

NOT_FOR_ARCHS=		powerpc
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: divide-by-zero error
.endif

.if ${ARCH} == "amd64"
MAKE_ARGS+=	MODEL=64
.else
MAKE_ARGS+=	MODEL=32
.endif

.if defined(WITH_DEBUG)
BUILD=		debug
MAKE_ARGS+=	DEBUG_FLAGS=-g\ -DDEBUG=1\ -DUNITTEST
.else
BUILD=		release
.endif

MODULEDIR=	${PREFIX}/include/d/phobos2

post-patch:
	@${REINPLACE_CMD} -e "s|g++|${CXX}|" ${WRKSRC}/posix.mak
	@${REINPLACE_CMD} -e "s|cc|${CC}|" ${WRKSRC}/../phobos/posix.mak
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|"	\
			  -e "s|\(dmd\)|\12|gI"		\
			  -e "s|\\\BR|.BR|"		\
		${WRKDIR}/dmd2/man/man1/dmd.1		\
		${WRKDIR}/dmd2/man/man1/dmd.conf.5
	@${REINPLACE_CMD} -e 's|"/etc/"|"${PREFIX}/etc/"|' ${WRKSRC}/inifile.c
	@${REINPLACE_CMD} -e 's|dmd.conf|dmd2.conf|' ${WRKSRC}/mars.c
	@${REINPLACE_CMD} -e "s|%@P%/../../src/phobos|${MODULEDIR}|"	\
			  -e "s|%@P%/../lib|${PREFIX}/lib|"		\
			  -e "s|%@P%/../../src/druntime|${PREFIX}/include/d/druntime|"	\
			  ${WRKDIR}/dmd2/linux/bin32/dmd.conf

post-build:
	cd ${WRKSRC}/../druntime && \
		${SETENV} PATH=${WRKSRC}:${PATH} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}
	cd ${WRKSRC}/../phobos && \
		${SETENV} PATH=${WRKSRC}:${PATH} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${BUILD}

do-install:
	${INSTALL_MAN} ${WRKDIR}/dmd2/man/man1/dmd.1 ${MANPREFIX}/man/man1/dmd2.1
	${INSTALL_MAN} ${WRKDIR}/dmd2/man/man1/dmd.conf.5 ${MANPREFIX}/man/man5/dmd2.conf.5
.if !exists(${PREFIX}/etc/dmd2.conf)
	${INSTALL_DATA} ${WRKDIR}/dmd2/linux/bin32/dmd.conf ${PREFIX}/etc/dmd2.conf
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/dmd ${PREFIX}/bin/dmd2
.if ${ARCH} == "amd64"
	${INSTALL_DATA} ${WRKSRC}/../phobos/generated/freebsd/${BUILD}/64/libphobos2.a ${PREFIX}/lib
.else
	${INSTALL_DATA} ${WRKSRC}/../phobos/generated/freebsd/${BUILD}/32/libphobos2.a ${PREFIX}/lib
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd2/linux/bin32/dmd.conf ${EXAMPLESDIR}/dmd2.conf
	cd ${WRKDIR}/dmd2 && ${COPYTREE_SHARE} samples ${EXAMPLESDIR}
	${MKDIR} ${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../phobos/*.d ${MODULEDIR}
	${MKDIR} ${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/zlib.d ${MODULEDIR}/etc/c
	cd ${WRKSRC}/../phobos && ${COPYTREE_SHARE} std ${MODULEDIR}
	${MKDIR} ${MODULEDIR}/../druntime
	cd ${WRKSRC}/../druntime && ${COPYTREE_SHARE} import ${MODULEDIR}/../druntime
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	cd ${WRKDIR}/dmd2 && ${COPYTREE_SHARE} html ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/druntime
	${INSTALL_DATA} ${WRKSRC}/../druntime/LICENSE ${DOCSDIR}/druntime
	${INSTALL_DATA} ${WRKSRC}/../druntime/README ${DOCSDIR}/druntime
	cd ${WRKSRC}/../druntime && ${COPYTREE_SHARE} doc ${DOCSDIR}/druntime
	${MKDIR} ${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/std.ddoc ${DOCSDIR}/phobos
.endif

.include <bsd.port.post.mk>
