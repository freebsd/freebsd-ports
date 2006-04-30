# New ports collection makefile for:	poppler-gtk
# Date created:		2006-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/poppler-gtk/Makefile,v 1.3 2006/03/09 01:49:50 marcus Exp $

PORTREVISION=	0
PKGNAMESUFFIX=	-gtk

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk bindings to poppler

MASTERDIR=	${.CURDIR}/../../graphics/poppler
SLAVEPORT=	gtk
PLIST=	${.CURDIR}/pkg-plist

pre-build:
	cd ${WRKSRC}/poppler && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} libpoppler-cairo.la

.include "${MASTERDIR}/Makefile"
