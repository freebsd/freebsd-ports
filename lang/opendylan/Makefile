# Created by: alepulver
# $FreeBSD$

PORTNAME=	opendylan
DISTVERSION=	2013.1
CATEGORIES=	lang
MASTER_SITES=	http://opendylan.org/downloads/opendylan/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-x86-freebsd

MAINTAINER=	hannes@mehnert.org
COMMENT=	Open Dylan project native command-line compiler for Dylan

IA32_BINARY_PORT=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
DATADIR=	${PREFIX}/lib/${PORTNAME}

WRAPPERS=	dylan-compiler make-dylan-app dswank parser-compiler

.include <bsd.port.options.mk>

do-build:
.for f in ${WRAPPERS}
	@(${ECHO_CMD} "#!${SH}"; \
	${ECHO_CMD} 'export LD_LIBRARY_PATH="${DATADIR}/lib"'; \
	${ECHO_CMD} 'exec ${DATADIR}/bin/${f} "$$@"') > ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${DATADIR}
.for d in bin databases lib sources
	${CP} -r ${WRKSRC}/${d} ${DATADIR}
.endfor
.for f in ${WRAPPERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
