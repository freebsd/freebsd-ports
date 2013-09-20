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

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		FLAC:${PORTSDIR}/audio/flac

PLIST_FILES=	lib/bmp/Input/libbmp-flac.so

NO_STAGE=	yes
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
	@${MKDIR} ${PREFIX}/lib/bmp/Input
	${INSTALL_DATA} ${WRKSRC}/src/plugin_bmp/.libs/libbmp-flac.so ${PREFIX}/lib/bmp/Input

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
