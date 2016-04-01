# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	libgltext
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/gltext/gltext/${PORTVERSION}
DISTNAME=	gltext-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable font rendering library for C++

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gmake libtool
USE_GL=		glu
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	EXAMPLES DOCS
EXAMPLES_DESC=	Compile examples, need libglut

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
USE_GL+=	glut
USE_XORG=	xmu
FLAG_EXAMPLES=	true
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PORTNAME}-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.la \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/gltext.h ${STAGEDIR}${PREFIX}/include

	@cd ${STAGEDIR}${PREFIX}/lib && \
		${LN} -s ${PORTNAME}.so.0 ${PORTNAME}.so

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${STAGEDIR}${DOCSDIR}
.endif

.if defined(FLAG_EXAMPLES)
.for DIRE in alpha fps simple sizes
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${DIRE}
	@cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${DIRE}/${DIRE} ${DIRE}/${DIRE}.cpp ${STAGEDIR}${EXAMPLESDIR}/${DIRE}
.endfor
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"		Examples source and binary on ${STAGEDIR}${EXAMPLESDIR}"
	@${ECHO_MSG}	""
.endif

.include <bsd.port.mk>
