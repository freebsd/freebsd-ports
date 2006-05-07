# ex:ts=8
# Ports collection makefile for:	vx68k
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vx68k
PORTVERSION=	1.1.10
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.hypercore.co.jp/vx68k/${PORTNAME}-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A virtual machine that emulates a Sharp X68000

LIB_DEPENDS=	vm68k.4:${PORTSDIR}/emulators/libvm68k

USE_GETTEXT=	yes
USE_GL=		yes
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure vx68k-gtk/configure
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	vx68k.1
INFO=	vx68k

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU \
		${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|Bison |Bison|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir| ; \
		s|LTLIBRELEASE=".*"|LTLIBRELEASE=|' \
		${WRKSRC}/configure ${WRKSRC}/vx68k-gtk/configure 
	@${REINPLACE_CMD} -e '/^#define _POSIX_C_SOURCE 199506L/d' \
		${WRKSRC}/vx68k-gtk/libvx68k-gtk/gl.cc \
		${WRKSRC}/vx68k-gtk/libvx68k-gtk/gtkconsole.cc

.include <bsd.port.mk>
