# New ports collection makefile for:	libgltext
# Date created:		2006-02-20
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	libgltext
PORTVERSION=	0.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gltext
DISTNAME=	gltext-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Portable font rendering library for C++

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes
USE_GL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

OPTIONS=	EXAMPLES	"Compile examples, need libglut"	off

.include <bsd.port.pre.mk>

.if defined(WITH_EXAMPLES)
LIB_DEPENDS+=	glut.4:${PORTSDIR}/graphics/libglut
FLAG_EXAMPLES=	true
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PORTNAME}-${PORTVERSION}.so \
		${PREFIX}/lib/${PORTNAME}.so.0
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${PORTNAME}.a \
		${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.la \
		${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/gltext.h ${PREFIX}/include

	@cd ${PREFIX}/lib && \
		${LN} -s ${PORTNAME}.so.0 ${PORTNAME}.so

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${DOCSDIR}
.endif

.if defined(FLAG_EXAMPLES)
.for DIRE in alpha fps simple sizes
	@${MKDIR} ${EXAMPLESDIR}/${DIRE}
	@cd ${WRKSRC}/examples && \
		${INSTALL_DATA} ${DIRE}/${DIRE} ${DIRE}/${DIRE}.cpp ${EXAMPLESDIR}/${DIRE}
.endfor
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"		Examples source and binary on ${EXAMPLESDIR}"
	@${ECHO_MSG}	""
.endif

.include <bsd.port.post.mk>
