# New ports collection makefile for:	desmume
# Date created:				Wed  7 Feb 2007 21:46:15 CET
# Whom:					Stefan Sperling <stsp@stsp.in-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	desmume
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	llc2w@virginia.edu
COMMENT=	Nintendo DS emulator

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt DATADIRNAME=share

USE_AUTOTOOLS=	aclocal:19 autoconf:262
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

post-patch:
	@${REINPLACE_CMD} -e 's|@MKDIR_P@|${MKDIR}|' ${WRKSRC}/src/cli/Makefile.in \
		${WRKSRC}/src/gtk/Makefile.in ${WRKSRC}/src/gtk-glade/Makefile.in \
		${WRKSRC}/src/gtk/doc/Makefile.in ${WRKSRC}/src/gtk-glade/doc/Makefile.in \
		${WRKSRC}/src/cli/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|../MMU.h|../&|' ${WRKSRC}/src/gtk/tools/ioregsView.cpp

.include <bsd.port.post.mk>
