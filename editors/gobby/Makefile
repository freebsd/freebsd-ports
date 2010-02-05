# Ports collection makefile for:  gobby
# Date created:			  28 September 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	gobby
PORTVERSION=	0.4.12
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free collaborative editor

LIB_DEPENDS=	obby-0.4.1:${PORTSDIR}/devel/obby \
		net6-1.3.0:${PORTSDIR}/net/net6 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS=	GTKSPELL "Enable GtkSpell support" off

USE_GNOME=	gnomehack gtksourceview2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if defined(WITH_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--with-gtkspell
.else
CONFIGURE_ARGS+=--without-gtkspell
.endif

.include <bsd.port.post.mk>
