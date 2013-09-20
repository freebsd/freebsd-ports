# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	ocrad
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXXFLAGS="${CXXFLAGS}" CXX="${CXX}"
CXXFLAGS+=	-Wall -W
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

PLIST_FILES=	bin/${PORTNAME}

MAN1=		ocrad.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
