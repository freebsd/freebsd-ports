# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	tenebrae
PORTVERSION=	1.04
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://tenebrae.sourceforge.net/downloads/
DISTFILES=	${PORTNAME}_src${EXTRACT_SUFX} \
		${PORTNAME}data${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake engine with lighting similar to that in Doom III

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake dos2unix zip
USE_GL=		glu
USE_SDL=	yes
USE_XORG=	xxf86dga

WRKSRC=		${WRKDIR}/${PORTNAME}_0
BUILD_WRKSRC=	${WRKSRC}/linux
MAKEFILE=	Makefile.i386linux
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_amd64=	ASM

ASM_MAKE_ENV=	USE_ASM=1

post-patch:
	${REINPLACE_CMD} -e 's|gray_1_2_4_to_8|expand_&|' \
		${WRKSRC}/gl_warp.c

pre-build:
	@cd ${BUILD_WRKSRC} && ${LN} -sf Makefile.i386linux Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Pak0.pak ${STAGEDIR}${Q1DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TR} -d '\r' < ${WRKDIR}/Tenebrae_Readme.txt \
		> ${STAGEDIR}${DOCSDIR}/Tenebrae_Readme.txt

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.mk>
