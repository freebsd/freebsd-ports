# ex:ts=8
# Ports collection makefile for:	ragel
# Date created:			Mar 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ragel
PORTVERSION=	6.7
CATEGORIES=	devel
MASTER_SITES=	http://www.complang.org/ragel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=|#CXXFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/[:.]c/!s/compare/this->&/' \
		${WRKSRC}/aapl/avlcommon.h \
		${WRKSRC}/aapl/bstcommon.h \
		${WRKSRC}/aapl/bubblesort.h \
		${WRKSRC}/aapl/mergesort.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
