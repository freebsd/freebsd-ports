# Created by: Stefan Sperling <stsp@stsp.in-berlin.de>
# $FreeBSD$

PORTNAME=	desmume
PORTVERSION=	0.9.8
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	llc2w@virginia.edu
COMMENT=	Nintendo DS emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		gl
USE_SDL=	sdl
USE_GNOME=	gtk20 libglade2
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt DATADIRNAME=share

USE_AUTOTOOLS=	aclocal autoconf
ACLOCAL_ARGS=
AUTOCONF_ARGS=

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -DGTKGLEXT_AVAILABLE \
		-DHAVE_LIBGDKGLEXT_X11_1_0 -DHAVE_GL_GL_H -DHAVE_GL_GLU_H
CXXFLAGS+=	${CFLAGS}

MAN1=		desmume-cli.1 \
		desmume-glade.1 \
		desmume.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

post-patch:
# FreeBSD 7.x is missing strnlen(), adjusting this enables a builtin version of strnlen()
.if ${OSVERSION} < 800000
	@${REINPLACE_CMD} -e 's|#ifdef __APPLE__|#if 1|g; \
			/AvailabilityMacros\.h/d' \
		${WRKSRC}/src/utils/libfat/directory.cpp
.endif

.include <bsd.port.post.mk>
