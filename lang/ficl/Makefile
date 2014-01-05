# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	ficl
PORTVERSION=	4.1.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all/${PORTNAME}${PORTVERSION:C/([[:digit:]]+\.[[:digit:]]+)\.0/\1/}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Forth Inspired Command Language

LICENSE=	unknown
LICENSE_NAME=	BSD-style
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://ficl.sourceforge.net/license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	YES

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	this port is not tested on anything other than i386 and amd64

USE_LDCONFIG=	YES

ALL_TARGET=	lib ${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.${PORTVERSION} lib/lib${PORTNAME}.a

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf lib${PORTNAME}.so.${PORTVERSION} lib${PORTNAME}.so

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/articles ${STAGEDIR}${DOCSDIR}/graphics; \
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.ico ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/articles/* ${STAGEDIR}${DOCSDIR}/articles
	${INSTALL_DATA} ${WRKSRC}/doc/graphics/* ${STAGEDIR}${DOCSDIR}/graphics
.endif

.include <bsd.port.mk>
