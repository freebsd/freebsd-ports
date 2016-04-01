# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	ocrad
PORTVERSION=	0.25
CATEGORIES=	graphics
MASTER_SITES=	GNU
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME} man/man1/ocrad.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000024
EXTRACT_DEPENDS=	lzip:archivers/lzip
EXTRACT_CMD=		${LOCALBASE}/bin/lzip
EXTRACT_BEFORE_ARGS=	-cd
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
