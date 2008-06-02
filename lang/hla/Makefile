# vim: ts=8
# New ports collection Makefile for:	hla
# Date created:				29 May 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	hla
PORTVERSION=	1.102
CATEGORIES=	lang
MASTER_SITES=	http://webster.cs.ucr.edu/AsmTools/HLA/HLAv${PORTVERSION}/:src \
		http://www.gahr.ch/FreeBSD/HLA/:extra
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME}src${EXTRACT_SUFX}:src \
		HLARef_html${EXTRACT_SUFX}:src \
		HLAStdlib_html${EXTRACT_SUFX}:src \
		linux.${PORTNAME}.tar.gz:src\
    		lex.yy.c:extra \
    		hello.hla:extra
EXTRACT_ONLY=	${PORTNAME}src${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High Level Assembly

USE_ZIP=	yes
USE_BISON=	build
USE_LINUX=	yes

WRKSRC=		${WRKDIR}/hlasrc/working
MAKEFILE=	makefile.bsd
ALL_TARGET=	hlaparse hla

ONLY_FOR_ARCHS=	i386

post-extract:
	${MKDIR} ${WRKDIR}/stdlib && \
	    ${TAR} -zxf ${DISTDIR}/linux.${PORTNAME}.tar.gz -C ${WRKDIR}/stdlib
	${CP} ${DISTDIR}/lex.yy.c ${WRKSRC}
	${CP} ${DISTDIR}/hello.hla ${WRKSRC}
.if !defined(NOPORTDOCS)
	(${MKDIR} ${WRKDIR}/HLAStdlib && \
	    ${UNZIP_CMD} -q ${DISTDIR}/HLAStdlib_html${EXTRACT_SUFX} -d ${WRKDIR}/HLAStdlib \
	)
	(${MKDIR} ${WRKDIR}/HLAReference && \
	    ${UNZIP_CMD} -q ${DISTDIR}/HLARef_html${EXTRACT_SUFX} -d ${WRKDIR}/HLAReference \
	)
.endif

post-patch:
	${REINPLACE_CMD} -e '/flex/d' ${WRKSRC}/makefile.bsd

do-configure:
	(cd ${WRKSRC} && bison -o hlaparse.c hlaparse.bsn)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hla ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hlaparse ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/stdlib/hla/hlalib/hlalib.a ${PREFIX}/lib
	${INSTALL} -d ${PREFIX}/include/hla
	(cd ${WRKDIR}/stdlib/hla/include && ${COPYTREE_SHARE} \* ${PREFIX}/include/hla)

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}/Reference
	${INSTALL} -d ${DOCSDIR}/Stdlib
	(cd ${WRKDIR}/HLAReference && ${COPYTREE_SHARE} \* ${DOCSDIR}/Reference)
	(cd ${WRKDIR}/HLAStdlib && ${COPYTREE_SHARE} \* ${DOCSDIR}/Stdlib)
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Testing HLA installation..."
	@( \
	    hlainc=${PREFIX}/include/hla hlalib=${PREFIX}/lib/hlalib.a \
	    ${WRKSRC}/hla ${WRKSRC}/hello.hla && \
	    ${BRANDELF} -t Linux ${WRKSRC}/hello && \
	    ${WRKSRC}/hello \
	)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Remember to set the following environment variables:"
	@${ECHO_MSG} "hlainc -> ${PREFIX}/include/hla"
	@${ECHO_MSG} "hlalib -> ${PREFIX}/lib/hlalib.a"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Remember that your executables must be run under the Linux ABI:"
	@${ECHO_MSG} "> hla hello.hla"
	@${ECHO_MSG} "> brandelf -t Linux hello"
	@${ECHO_MSG} "> ./hello"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
