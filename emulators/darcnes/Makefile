# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darcnes
PORTVERSION=	9b0401
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/ \
		LOCAL/grembo
DISTNAME=	dn${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	multi-system emulator

NO_CDROM=	Commercial use is restricted

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_GNOME=	yes
USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" TARGET_CC="${CC}" CXX="${CXX}" TARGET_CXX="${CXX}" \
		AS="${AS}" TARGET_AS="${CC}" LD="${LD}" TARGET_LD="${CC}"

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	X11 GTK1 SVGALIB
OPTIONS_DEFAULT=X11
BACKEND_DESC=	GUI backend

.include <bsd.port.options.mk>

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	C_ONLY=-DC_ONLY
.else
MAKE_ARGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.endif

.if ${PORT_OPTIONS:MGTK1}
USE_GNOME=	gtk12
MAKE_ARGS+=	TARGET=Linux_GTK
PKGNAMESUFFIX=	-gtk
.endif

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=	libvga.so:graphics/svgalib
MAKE_ARGS+=	TARGET=Linux_svgalib
PKGNAMESUFFIX=	-svgalib
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xaw xext xmu xt
.endif

post-patch:
	@${CP} ${FILESDIR}/endian.h ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
