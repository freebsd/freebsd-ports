# Created by: alepulver
# $FreeBSD$

PORTNAME=	opendylan
DISTVERSION=	2013.2
CATEGORIES=	lang
MASTER_SITES=	http://opendylan.org/downloads/opendylan/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-x86-freebsd

MAINTAINER=	hannes@mehnert.org
COMMENT=	Open Dylan project native command-line compiler for Dylan

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

IA32_BINARY_PORT=	yes
USES=		tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
DATADIR=	${PREFIX}/lib/${PORTNAME}

WRAPPERS=	dylan-compiler make-dylan-app dswank parser-compiler

OPTIONS_DEFINE=	DOCS

do-build:
.for f in ${WRAPPERS}
	@(${ECHO_CMD} "#!${SH}"; \
	${ECHO_CMD} 'export LD_LIBRARY_PATH="${DATADIR}/lib"'; \
	${ECHO_CMD} 'exec ${DATADIR}/bin/${f} "$$@"') > ${WRKSRC}/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in bin databases lib sources
	${CP} -r ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor
.for f in ${WRAPPERS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
