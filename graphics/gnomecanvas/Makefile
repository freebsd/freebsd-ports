# New ports collection makefile for:	gnomecanvas
# Date created:				18 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomecanvas
CATEGORIES=	graphics gnome

COMMENT=	A graphics library for GNOME

MASTERDIR=	${.CURDIR}/../gdk-pixbuf
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gdkpixbuf gnomelibs

BUILD_CANVAS=	yes

NAME=	gnomecanvaspixbuf

do-install:
	${INSTALL_DATA} ${WRKSRC}/${NAME}Conf.sh ${PREFIX}/etc
	cd ${WRKSRC}/gdk-pixbuf/.libs && \
		${MKDIR} ${PREFIX}/include/gdk-pixbuf-1.0/gdk-pixbuf && \
		${INSTALL_DATA} ../gnome-canvas-pixbuf.h ${PREFIX}/include/gdk-pixbuf-1.0/gdk-pixbuf && \
		${INSTALL_DATA} lib${NAME}.a ${PREFIX}/lib && \
		${INSTALL_PROGRAM} lib${NAME}.so.1 ${PREFIX}/lib && \
		${LN} -sf lib${NAME}.so.1 ${PREFIX}/lib/lib${NAME}.so

.include "${MASTERDIR}/Makefile"
