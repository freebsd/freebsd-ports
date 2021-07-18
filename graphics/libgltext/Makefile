# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>

PORTNAME=	libgltext
PORTVERSION=	0.3.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/gltext/gltext/${PORTVERSION}
DISTNAME=	gltext-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable font rendering library for C++

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gl gmake localbase libtool xorg
USE_GL=		gl glu
USE_XORG=	x11 xmu
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES DOCS
OPTIONS_SUB=	yes
EXAMPLES_DESC=	Compile examples, need libglut
EXAMPLES_USE=	GL=glut

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PORTNAME}-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.la \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/gltext.h ${STAGEDIR}${PREFIX}/include
	${LN} -s ${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
.for DIRE in alpha fps simple sizes
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${DIRE}
	cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${DIRE}/${DIRE} ${DIRE}/${DIRE}.cpp ${STAGEDIR}${EXAMPLESDIR}/${DIRE}
.endfor
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"		Examples source and binary on ${STAGEDIR}${EXAMPLESDIR}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
