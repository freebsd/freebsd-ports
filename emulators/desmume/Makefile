# New ports collection makefile for:	desmume
# Date created:				Wed  7 Feb 2007 21:46:15 CET
# Whom:					Stefan Sperling <stsp@stsp.in-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	desmume
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	llc2w@virginia.edu
COMMENT=	Nintendo DS emulator

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt DATADIRNAME=share

USE_AUTOTOOLS=	aclocal:111 autoconf:268
ACLOCAL_ARGS=
AUTOCONF_ARGS=

CXXFLAGS+=	-I${LOCALBASE}/include -DGTKGLEXT_AVAILABLE -DHAVE_LIBGDKGLEXT_X11_1_0 \
		-DHAVE_GL_GL_H -DHAVE_GL_GLU_H

MAN1=		desmume-cli.1 \
		desmume-glade.1 \
		desmume.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
