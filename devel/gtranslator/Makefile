# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtranslator
PORTVERSION=	1.1.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME application for creating GNU gettext translation files

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnometarget gnomevfs2 libgnomeui
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_ARGS=	--disable-debug \
		--enable-compile-warnings=no \
		--mandir=${PREFIX}/man

MAN1=		gtranslator.1 pozilla.sh.1

post-patch:
		@${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
