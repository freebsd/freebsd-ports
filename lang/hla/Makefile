# Created by: gahr
# $FreeBSD$

PORTNAME=	hla
PORTVERSION=	1.103
CATEGORIES=	lang
MASTER_SITES=	http://webster.cs.ucr.edu/AsmTools/HLA/HLAv${PORTVERSION}/:src \
		http://www.gahr.ch/FreeBSD/HLA/:extra
DISTFILES=	${PORTNAME}src${EXTRACT_SUFX}:src \
		bsd.hla.tar.gz:src \
		HLARef_html${EXTRACT_SUFX}:src \
		HLAstdlib_html${EXTRACT_SUFX}:src \
    		lex.yy.c:extra \
    		hello.hla:extra
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}src${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	High Level Assembly

USES=		bison zip:infozip

WRKSRC=		${WRKDIR}/hlasrc/trunk/trunk
MAKEFILE=	makefile.bsd
ALL_TARGET=	hlaparse hla

ONLY_FOR_ARCHS=	i386

NO_STAGE=	yes
post-extract:
	${MKDIR} ${WRKDIR}/stdlib && \
	    ${TAR} -zxf ${_DISTDIR}/bsd.${PORTNAME}.tar.gz -C ${WRKDIR}/stdlib
	${CP} ${_DISTDIR}/lex.yy.c ${WRKSRC}
	${CP} ${_DISTDIR}/hello.hla ${WRKSRC}
.if !defined(NOPORTDOCS)
	(${MKDIR} ${WRKDIR}/HLAstdlib && \
	    ${UNZIP_CMD} -q ${_DISTDIR}/HLAstdlib_html${EXTRACT_SUFX} -d ${WRKDIR}/HLAstdlib \
	)
	(${MKDIR} ${WRKDIR}/HLAReference && \
	    ${UNZIP_CMD} -q ${_DISTDIR}/HLARef_html${EXTRACT_SUFX} -d ${WRKDIR}/HLAReference \
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
	(cd ${WRKDIR}/stdlib/hla/include/include && ${COPYTREE_SHARE} \* ${PREFIX}/include/hla)

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}/Reference
	${INSTALL} -d ${DOCSDIR}/stdlib
	(cd ${WRKDIR}/HLAReference && ${COPYTREE_SHARE} \* ${DOCSDIR}/Reference)
	(cd ${WRKDIR}/HLAstdlib && ${COPYTREE_SHARE} \* ${DOCSDIR}/stdlib)
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Testing HLA installation..."
	@( \
	    hlainc=${PREFIX}/include/hla hlalib=${PREFIX}/lib/hlalib.a \
	    ${WRKSRC}/hla ${WRKSRC}/hello.hla && \
	    ${WRKSRC}/hello \
	)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Remember to set the following environment variables:"
	@${ECHO_MSG} "hlainc -> ${PREFIX}/include/hla"
	@${ECHO_MSG} "hlalib -> ${PREFIX}/lib/hlalib.a"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
