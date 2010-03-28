# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf-gnome/Makefile,v 1.12 2008/09/09 00:08:35 kwm Exp $
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

USE_GNOME=	gnomehack libgsf gnomevfs2 libbonobo ltverhack intlhack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--with-bz2 --with-gnome-vfs --with-gio
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgsf-1"

GSF_SLAVE=	yes

post-install:
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc \
		${PREFIX}/libdata/pkgconfig/

.include "${MASTERDIR}/Makefile"
