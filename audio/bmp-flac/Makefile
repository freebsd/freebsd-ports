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

LIB_DEPENDS=	libbeep.so:${PORTSDIR}/multimedia/beep-media-player \
		libFLAC.so:${PORTSDIR}/audio/flac

PLIST_FILES=	lib/bmp/Input/libbmp-flac.so

USES=		iconv pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${LOCALBASE}"

MAKEFILE=	${FILESDIR}/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

# "obj" is magic to our make(1)
# make sure we get the new includes from ${LOCALBASE}/include/FLAC
post-configure:
	@${RM} -rf ${WRKSRC}/obj
	@${RM} -rf ${WRKSRC}/include/FLAC

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/bmp/Input
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bmp/Input
	${INSTALL_LIB} ${WRKSRC}/src/plugin_bmp/.libs/libbmp-flac.so ${STAGEDIR}${PREFIX}/lib/bmp/Input

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
