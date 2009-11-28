# New ports collection makefile for:	gir-repository
# Date created:				14 Aug 2009
# Whom:					Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/devel/gir-repository/Makefile,v 1.9 2009/11/09 09:29:14 kwm Exp $
#

MASTER_SITES=	# Empty
DISTFILES=	# None
PATCHDIR=	# None

CATEGORIES=	devel gnome

COMMENT=	Introspection information for various libraries

NO_BUILD=	yes

RUN_DEPENDS=	${GIRDIR}/${atk_GIR}.gir:${PORTSDIR}/${atk_CATEGORY}/gir-repository-atk \
		${GIRDIR}/${pango_GIR}.gir:${PORTSDIR}/${pango_CATEGORY}/gir-repository-pango \
		${GIRDIR}/${poppler_GIR}.gir:${PORTSDIR}/${poppler_CATEGORY}/gir-repository-poppler \
		${GIRDIR}/${gtk20_GIR}.gir:${PORTSDIR}/${gtk20_CATEGORY}/gir-repository-gtk20 \
		${GIRDIR}/${webkit_GIR}.gir:${PORTSDIR}/${webkit_CATEGORY}/gir-repository-webkit \
		${GIRDIR}/${libsoup_GIR}.gir:${PORTSDIR}/${libsoup_CATEGORY}/gir-repository-libsoup \
		${GIRDIR}/${dbus_GIR}.gir:${PORTSDIR}/${dbus_CATEGORY}/gir-repository-dbus \
		${GIRDIR}/${gconf2_GIR}.gir:${PORTSDIR}/${gconf2_CATEGORY}/gir-repository-gconf2 \
		${GIRDIR}/${babl_GIR}.gir:${PORTSDIR}/${babl_CATEGORY}/gir-repository-babl \
		${GIRDIR}/${nautilus_GIR}.gir:${PORTSDIR}/${nautilus_CATEGORY}/gir-repository-nautilus \
		${GIRDIR}/${gnomekeyring_GIR}.gir:${PORTSDIR}/${gnomekeyring_CATEGORY}/gir-repository-gnome-keyring \
		${GIRDIR}/${libnotify_GIR}.gir:${PORTSDIR}/${libnotify_CATEGORY}/gir-repository-libnotify \
		${GIRDIR}/${gtksourceview2_GIR}.gir:${PORTSDIR}/${gtksourceview2_CATEGORY}/gir-repository-gtksourceview2 \
		${GIRDIR}/${vte_GIR}.gir:${PORTSDIR}/${vte_CATEGORY}/gir-repository-vte \
		${GIRDIR}/${avahi_GIR}.gir:${PORTSDIR}/${avahi_CATEGORY}/gir-repository-avahi \
		${GIRDIR}/${gnomemenus_GIR}.gir:${PORTSDIR}/${gnomemenus_CATEGORY}/gir-repository-gnome-menus \
		${GIRDIR}/${libwnck_GIR}.gir:${PORTSDIR}/${libwnck_CATEGORY}/gir-repository-libwnck \
		${GIRDIR}/${goocanvas_GIR}.gir:${PORTSDIR}/${goocanvas_CATEGORY}/gir-repository-goocanvas

do-install:	# empty

.include "${.CURDIR}/../../devel/gir-repository/bsd.gir.mk"
