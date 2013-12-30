# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aumix
PORTVERSION=	2.9.1
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/

MAINTAINER=	unix4all@gulic.org
COMMENT=	Audio mixer for X11, terminal, or command line

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--enable-own-labels \
		--libdir="${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_DIRS=	share/aumix
PLIST_FILES=	bin/aumix bin/mute bin/xaumix \
		man/man1/aumix.1.gz \
		man/man1/xaumix.1.gz \
		man/man1/mute.1.gz
.for ii in ansi aumix.xpm fadein.set fadeout.set vt100 xterm
PLIST_FILES+=	share/aumix/${ii}
.endfor

OPTIONS_DEFINE=	NLS GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext

.for ii in ca de el es fr gl it ja nl pl pt_BR ru sv uk zh_CN
PLIST_FILES+=	share/locale/${ii}/LC_MESSAGES/aumix.mo
.endfor
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--without-gtk
.endif

pre-patch:
	@${REINPLACE_CMD} -e "s:/etc:${PREFIX}/etc:" ${WRKSRC}/src/common.[ch]

.include <bsd.port.mk>
