# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf-gnome/Makefile,v 1.14 2010/04/10 08:51:16 kwm Exp $
#

PORTREVISION=	1
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME wrapper for libgsf

MASTERDIR=	${.CURDIR}/../libgsf
BUILD_WRKSRC=	${WRKSRC}/gsf-gnome
INSTALL_WRKSRC=	${WRKSRC}/gsf-gnome
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

DEPRECATED=    -gnome support in libgsf is dropped in newer versions.
EXPIRATION_DATE=2013-04-12

USE_GNOME=	gnomehack libgsf gnomevfs2 libbonobo ltverhack intlhack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--with-bz2 --with-gnome-vfs --with-gio
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgsf-1

GSF_SLAVE=	yes

post-install:
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc \
		${PREFIX}/libdata/pkgconfig/

.include "${MASTERDIR}/Makefile"
