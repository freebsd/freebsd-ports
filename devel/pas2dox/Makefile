# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	pas2dox
DISTVERSION=	0.50rc1
CATEGORIES=	devel converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.50rc1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Preprocessor to use doxygen with Pascal sources

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>0:${PORTSDIR}/textproc/flex
MAKE_ENV+=	LEX="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^LEX=|LEX?=| ; \
		 s|$${CC} $$<|$${CXX} $${CXXFLAGS} $$<|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|yy_flex_realloc|yyrealloc|' ${WRKSRC}/${PORTNAME}.l

pre-build:
	@${RM} -f ${WRKSRC}/${PORTNAME}.cpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.post.mk>
