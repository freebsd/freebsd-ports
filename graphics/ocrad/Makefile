# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	ocrad
PORTVERSION=	0.22
CATEGORIES=	graphics
MASTER_SITES=	GNU
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXXFLAGS="${CXXFLAGS}" CXX="${CXX}"
CXXFLAGS+=	-Wall -W
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

PLIST_FILES=	bin/${PORTNAME} man/man1/ocrad.1.gz

PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000024
EXTRACT_DEPENDS=lzip:${PORTSDIR}/archivers/lzip
EXTRACT_CMD=	${LOCALBASE}/bin/lzip
EXTRACT_BEFORE_ARGS=	-cd
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
