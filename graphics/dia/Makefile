# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.84
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/dia

MAINTAINER=	saper@system.pl

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12  \
		xml.5:${PORTSDIR}/textproc/libxml	\
		gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_X_PREFIX=   yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		dia.1

.include <bsd.port.mk>
