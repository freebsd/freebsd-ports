# New ports collection makefile for:	aumix
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aumix
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Audio mixer for X11, terminal, or command line

USE_BZIP2=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--enable-own-labels \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		aumix.1 xaumix.1
PLIST_DIRS=	share/aumix
PLIST_FILES=	bin/aumix bin/mute bin/xaumix
.for ii in ansi aumix.xpm fadein.set fadeout.set vt100 xterm
PLIST_FILES+=	share/aumix/${ii}
.endfor
.for ii in de el es fr gl ja nl pl pt_BR ru sv uk zh_CN
PLIST_FILES+=	share/locale/${ii}/LC_MESSAGES/aumix.mo
.endfor
.include <bsd.port.pre.mk>

pre-extract:
.if !defined(WITH_GTK2) && !defined(WITHOUT_ALL)
	@${ECHO_CMD}
	@${ECHO_CMD} "****** To enable use of GTK+ 2.0, interrupt the   ******"
	@${ECHO_CMD} "****** build now, set WITH_GTK2, and start again. ******"
	@${ECHO_CMD}
	@sleep 3
.endif

do-patch:
.for ii in c h
	${CP} -p ${WRKSRC}/src/common.${ii} ${WRKSRC}/src/common.${ii}.orig
	${SED} -e "s:/etc:${PREFIX}/etc:" < ${WRKSRC}/src/common.${ii}.orig \
		> ${WRKSRC}/src/common.${ii}
.endfor

.if (${HAVE_GNOME:Mgtk12}!="") && !defined(WITHOUT_ALL) && \
	!defined(WITHOUT_GTK)&& !defined(WITH_GTK2)
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk
CONFIGURE_ARGS+=--without-gtk
.elif defined(WITH_GTK2)
PKGNAMESUFFIX=	-gtk
LIB_DEPENDS+=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20
CONFIGURE_ARGS+=--without-gtk1
.else
CONFIGURE_ARGS+=--without-gtk --without-gtk1
.endif

.include <bsd.port.post.mk>
