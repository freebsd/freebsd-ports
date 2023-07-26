PORTNAME=	snack
PORTVERSION=	2.2.10
PORTREVISION=	7
CATEGORIES=	audio tcl tk
MASTER_SITES=	http://www.speech.kth.se/snack/dist/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound toolkit for scripting languages
WWW=		https://www.speech.kth.se/snack/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		tk:tea xorg
USE_LDCONFIG=	${PREFIX}/lib/snack${PORTVERSION:R}
USE_XORG=	x11 xscrnsaver xext xft xrender

MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC_SUBDIR=	unix

PLIST_SUB=	SNACK_VER=${PORTVERSION:R}
PORTDOCS=	*

OPTIONS_DEFINE=	VORBIS DOCS
OPTIONS_SUB=	yes

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ON=	--with-ogg-include=${LOCALBASE}/include \
			--with-ogg-lib=${LOCALBASE}/lib
VORBIS_ALL_TARGET=	all libsnackogg.so

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/snack${PORTVERSION:R}/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
