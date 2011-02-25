# New ports collection makefile for:	gir-repository
# Date created:				14 Aug 2009
# Whom:					Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/devel/gir-repository/Makefile,v 1.21 2010/10/24 16:26:19 avl Exp $
#

MASTER_SITES=	# Empty
DISTFILES=	# None
PATCHDIR=	# None

CATEGORIES=	devel gnome

COMMENT=	Introspection information for various libraries

NO_BUILD=	yes

RUN_DEPENDS=	${GIRDIR}/${poppler_GIR}.gir:${PORTSDIR}/${poppler_CATEGORY}/gir-repository-poppler \
		${GIRDIR}/${libnotify_GIR}.gir:${PORTSDIR}/${libnotify_CATEGORY}/gir-repository-libnotify \
		${GIRDIR}/${vte_GIR}.gir:${PORTSDIR}/${vte_CATEGORY}/gir-repository-vte \
		${GIRDIR}/${goocanvas_GIR}.gir:${PORTSDIR}/${goocanvas_CATEGORY}/gir-repository-goocanvas

do-install:	# empty

.include "${.CURDIR}/../../devel/gir-repository/bsd.gir.mk"
