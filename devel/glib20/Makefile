# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/${PORTNAME}/2.4,} \
		ftp://ftp.gtk.org/pub/gtk/v2.3/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv=gnu \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-man --without-xml-catalog
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

pre-everything::
	@${ECHO_CMD} '******************************************'
	@${ECHO_CMD}
	@${ECHO_CMD} If you have not updated your GNOME ports in the manner outlined in
	@${ECHO_CMD}   http://www.FreeBSD.org/gnome/docs/faq26.html
	@${ECHO_CMD} then you should abort this build immediately and follow the directions
	@${ECHO_CMD} outlined in that document.
	@${ECHO_CMD}
	@${ECHO_CMD} Failure to follow the above directions will result in everything
	@${ECHO_CMD} GNOME-related breaking.
	@${ECHO_CMD}
	@${ECHO_CMD} '******************************************'

.include <bsd.port.mk>
