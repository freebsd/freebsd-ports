# New ports collection makefile for:   darcnes
# Date created:        22 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcnes
PORTVERSION=	9b0401
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/
DISTNAME=	dn${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	multi-system emulator

NO_CDROM=	Commercial use is restricted

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_GNOME=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" TARGET_CC="${CC}" CXX="${CXX}" TARGET_CXX="${CXX}" \
		AS="${AS}" TARGET_AS="${CC}" LD="${LD}" TARGET_LD="${CC}"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	C_ONLY=-DC_ONLY
.else
MAKE_ARGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME=	gtk12
MAKE_ARGS+=	TARGET=Linux_GTK
PKGNAMESUFFIX=	-gtk
.else
.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
MAKE_ARGS+=	TARGET=Linux_svgalib
PKGNAMESUFFIX=	-svgalib
.else
USE_XLIB=	yes
.endif
.endif

post-patch:
	@${CP} ${FILESDIR}/endian.h ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
