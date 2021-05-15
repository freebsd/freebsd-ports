# Created by: Yukihiro Nakai <nakai@FreeBSD.org>

PORTNAME=	darcnes
PORTVERSION=	9b0401
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/ \
		LOCAL/grembo
DISTNAME=	dn${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-system emulator

# Converted from NO_CDROM
LICENSE=	darcnes-license
LICENSE_NAME=	darcnes
LICENSE_TEXT=	Commercial use is restricted
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" TARGET_CC="${CC}" CXX="${CXX}" TARGET_CXX="${CXX}" \
		AS="${AS}" TARGET_AS="${CC}" LD="${LD}" TARGET_LD="${CC}"

PLIST_FILES=	bin/darcnes
PORTDOCS=	readme

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	X11 SVGALIB
OPTIONS_DEFAULT=X11
BACKEND_DESC=	GUI backend

SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_VARS=		MAKE_ARGS+=TARGET=Linux_svgalib

X11_USES=	xorg
X11_USE=	XORG=x11,xaw,xext,xmu,xt

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	C_ONLY=-DC_ONLY
.else
MAKE_ARGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.endif

post-patch:
	@${CP} ${FILESDIR}/endian.h ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
