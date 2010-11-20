# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libsoup-gnome/Makefile,v 1.1 2010/06/05 21:11:10 kwm Exp $
#

PORTREVISION=	0
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME wrapper for libsoup

MASTERDIR=	${.CURDIR}/../libsoup
#BUILD_WRKSRC=	${WRKSRC}/gsf-gnome
#INSTALL_WRKSRC=	${WRKSRC}/gsf-gnome
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

SOUP_SLAVE=	yes

#post-install:
#	@${MKDIR} ${PREFIX}/libdata/pkgconfig
#	@${INSTALL_DATA} ${WRKSRC}/libsoup-gnome-2.4.pc \
#		${PREFIX}/libdata/pkgconfig/

.include "${MASTERDIR}/Makefile"
