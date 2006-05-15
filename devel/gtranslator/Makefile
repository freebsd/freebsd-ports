# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtranslator
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME application for creating GNU gettext translation files

LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnometarget gnomevfs2 libgnomeui
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_ARGS=	--disable-debug \
		--enable-compile-warnings=no

MAN1=		gtranslator.1 pozilla.sh.1
MANCOMPRESSED=	yes

post-patch:
	        @${REINPLACE_CMD} -e "s|/usr/local/share/gtranslator|${PREFIX}/share/gnome/${PORTNAME}|g; \
			s|/usr/local/share/pixmaps|${PREFIX}/share/gnome/pixmaps|g" \
			${WRKSRC}/src/defines.h
		@${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
