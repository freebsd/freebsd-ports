# New ports collection makefile for:	aumix
# Date created:        21 May 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aumix
PORTVERSION=	2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://jpj.net/~trevor/aumix/ \
		http://jpj.net/~trevor/aumix/old/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--enable-own-labels \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		aumix.1 xaumix.1

.include <bsd.port.pre.mk>

pre-extract:
.if !defined(WITH_GTK2) && !defined(WITHOUT_ALL)
	@${ECHO_CMD}
	@${ECHO_CMD} "****** To enable use of GTK+ 2.0, interrupt the   ******"
	@${ECHO_CMD} "****** build now, set WITH_GTK2, and start again. ******"
	@${ECHO_CMD}
	@sleep 3
.endif

.if (${HAVE_GNOME:Mgtk12}!="") && !defined(WITHOUT_ALL) && \
	!defined(WITHOUT_GTK)&& !defined(WITH_GTK2)
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk
CONFIGURE_ARGS+=--without-gtk
.elif defined(WITH_GTK2)
PKGNAMESUFFIX=	-gtk
LIB_DEPENDS+=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
CONFIGURE_ARGS+=--without-gtk1
.else
CONFIGURE_ARGS+=--without-gtk --without-gtk1
.endif

.include <bsd.port.post.mk>
