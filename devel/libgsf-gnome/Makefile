# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf-gnome/Makefile,v 1.10 2006/03/05 21:26:56 marcus Exp $
#

CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME wrapper for libgsf

MASTERDIR=	${.CURDIR}/../libgsf
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack libgsf gnomevfs2 ltverhack intlhack
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--disable-gtk-doc --with-bz2 --with-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lgsf-1"

GCONF_SCHEMAS=
GSF_SLAVE=	yes

do-build:
		@cd ${WRKSRC}/gsf-gnome && ${MAKE}

do-install:
		cd ${WRKSRC}/gsf-gnome && ${MAKE} ${INSTALL_TARGET}
		${MKDIR} ${PREFIX}/libdata/pkgconfig
		${INSTALL_DATA} ${WRKSRC}/libgsf-gnome-1.pc ${PREFIX}/libdata/pkgconfig

.include "${MASTERDIR}/Makefile"
