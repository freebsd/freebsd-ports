# New ports collection makefile for:	jpeg
# Date created:		6 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	jpeg-mmx
PORTVERSION=	0.1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	IJG's jpeg compression utilities with MMX optimization

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	cjpeg:${PORTSDIR}/graphics/jpeg

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/jpeg-mmx
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
USE_GCC=	3.4+

JPEG_EXT=	-mmx
INCDIR=		include/${PORTNAME}

BIN_FILES=	cjpeg djpeg jpegtran
INC_FILES=	jconfig.h jerror.h jinclude.h jmorecfg.h jpegint.h jpeglib.h
LIB_FILES=	libjpeg-mmx.a libjpeg-mmx.so libjpeg-mmx.so.62

PORTDOCS=	README coderules.doc filelist.doc install.doc jconfig.doc \
		libjpeg.doc structure.doc usage.doc wizard.doc
PLIST_DIRS=	include/jpeg-mmx
PLIST_FILES=	${BIN_FILES:S|^|bin/|:S|$|${JPEG_EXT}|} \
		${INC_FILES:S|^|${INCDIR}/|} \
		${LIB_FILES:S|^|lib/|}

# define J_MAXMEM like "make J_MAXMEM=32" to limit max processing memory to 32Mb
.if defined(J_MAXMEM)
CONFIGURE_ARGS+=	--enable-maxmem=${J_MAXMEM}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|./libtool|${LIBTOOL} --tag=CXX|' \
		${WRKSRC}/configure

do-install:
.for f in ${BIN_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/${f} ${PREFIX}/bin/${f}${JPEG_EXT}
.endfor
	@${MKDIR} ${PREFIX}/${INCDIR}
.for f in ${INC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${INCDIR}
.endfor
.for f in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/.libs/${f} ${PREFIX}/lib/
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
