# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	20040316
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://ccm.sherry.jp/tmp/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PORTNAME}-CVS-${PORTVERSION}-with-bmp-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FLAC input plugin for beep-media-player

LICENSE=	GPLv2

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libbeep.so:${PORTSDIR}/multimedia/beep-media-player

USE_BZIP2=	yes
USES=		iconv pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${LOCALBASE}"
MAKEFILE=	${FILESDIR}/Makefile

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/bmp/Input/libbmp-flac.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/xtra_stdcpp/s|-lstdc++||' ${WRKSRC}/configure

# "obj" is magic to our make(1)
# make sure we get the new includes from ${LOCALBASE}/include/FLAC
post-configure:
	@${RM} -rf ${WRKSRC}/obj
	@${RM} -rf ${WRKSRC}/include/FLAC

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/bmp/Input
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bmp/Input
	(cd ${WRKSRC}/src/plugin_bmp/.libs && ${INSTALL_LIB} libbmp-flac.so \
		${STAGEDIR}${PREFIX}/lib/bmp/Input)

.include <bsd.port.post.mk>
