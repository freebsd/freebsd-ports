# New ports collection makefile for:   generator
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gtk12
USE_SDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-raze
.else
CONFIGURE_ARGS+=	--with-cmz80
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g ; \
		 s|-minline-all-stringops||g ; \
		 s|-march=pentium||g ; \
		 s|-malign-loops=5||g ; \
		 s|-malign-jumps=5||g ; \
		 s|-malign-functions=5||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
