# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtranslator
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.gtranslator.org/download/releases/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME application for developing ".pot" files used with GNU Gettext

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomevfs2 libgnomeui 
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_ARGS=	--disable-debug
USE_REINPLACE=	yes

MAN1=		gtranslator.1 pozilla.sh.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/share/gtranslator|${DATADIR}|g; \
		s|/usr/share/pixmaps|${PREFIX}/share/gnome/pixmaps|g" \
		${WRKSRC}/src/defines.h

.include <bsd.port.mk>
