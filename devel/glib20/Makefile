# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glib20/Makefile,v 1.143 2009/03/27 18:52:46 marcus Exp $
#
# !! DON'T FORGET ABOUT devel/gio-fam-backend !!

PORTNAME=	glib
PORTVERSION=	2.20.3
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/glib/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/},} \
		ftp://ftp.gtk.org/pub/glib/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

LATEST_LINK=	glib20

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig ltverhack
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_PYTHON=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv=gnu \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-man --without-xml-catalog \
		--with-pcre=system \
		--disable-fam
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS=	COLLATION_FIX "fix string collation" off

.include <bsd.port.pre.mk>

# Let glib use asm code for implementing atomic ops on i386 and amd64.
.if ${ARCH} == "i386"
GLIB_ARCH=	i486
.elif ${ARCH} == "amd64"
GLIB_ARCH=	x86_64
.else
GLIB_ARCH=	${ARCH}
.endif
CONFIGURE_TARGET=${GLIB_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_COLLATION_FIX)
LIB_DEPENDS+=	icui18n:${PORTSDIR}/devel/icu
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-glib_Makefile.in \
		${FILESDIR}/extra-patch-glib_gunicollate.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/glib/gutils.c

.include <bsd.port.post.mk>

.endif
