# $FreeBSD$

PORTNAME=	tcc
PORTVERSION=	0.9.26
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SAVANNAH/tinycc

MAINTAINER=	cpm@fbsd.es
COMMENT=	Tiny C Compiler

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	i386

CONFLICTS=	TenDRA-[0-9]*

USES=		gmake makeinfo perl5 tar:bzip2
USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}"
MAKE_ARGS=	CONFIG_NOLDL=1

OPTIONS_DEFINE=	DOCS EXAMPLES

INFO=		tcc-doc
PORTDOCS=	COPYING	Changelog README TODO VERSION

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${CC:T:M*clang*} || ${OSVERSION} >= 1000024
CFLAGS+=	-fheinous-gnu-extensions
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tcc
	${INSTALL_MAN} ${WRKSRC}/tcc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${INSTALL_DATA} ${WRKSRC}/lib/i386/bcheck.o ${STAGEDIR}${PREFIX}/lib/tcc

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tcc-doc.info ${STAGEDIR}${PREFIX}/info
	${RM} -r ${STAGEDIR}${PREFIX}/share/info
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
