# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME wrapper for libgsf

MASTERDIR=	${.CURDIR}/../libgsf
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack libgsf gnomevfs2
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--disable-gtk-doc --with-bz2 --with-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgsf-1"

do-build:
		@cd ${WRKSRC}/gsf-gnome && ${MAKE}

do-install:
		cd ${WRKSRC}/gsf-gnome && ${MAKE} install
		${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc ${PREFIX}/libdata/pkgconfig

.include "${MASTERDIR}/Makefile"
