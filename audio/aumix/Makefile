# New ports collection makefile for:	aumix
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		aumix.1 xaumix.1 mute.1
PLIST_DIRS=	share/aumix
PLIST_FILES=	bin/aumix bin/mute bin/xaumix
.for ii in ansi aumix.xpm fadein.set fadeout.set vt100 xterm
PLIST_FILES+=	share/aumix/${ii}
.endfor

OPTIONS=	NLS	"Enable NLS support" on \
		GTK2	"Enable GTK2 gui" off

.include <bsd.port.pre.mk>
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes

.for ii in ca de el es fr gl it ja nl pl pt_BR ru sv uk zh_CN
PLIST_FILES+=	share/locale/${ii}/LC_MESSAGES/aumix.mo
.endfor
.endif

pre-patch:
	@${REINPLACE_CMD} -e "s:/etc:${PREFIX}/etc:" ${WRKSRC}/src/common.[ch]

.if defined(WITH_GTK2)
PKGNAMESUFFIX=	-gtk
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--without-gtk
.endif

.include <bsd.port.post.mk>
