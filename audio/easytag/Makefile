# ex:ts=8
# New ports collection makefile for:	easytag
# Date created:			May 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dominic_marks@btinternet.com

LIB_DEPENDS=	id3-3.7.13:${PORTSDIR}/audio/id3lib \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_GTK=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e 's|`gtk-config |`\$$GTK_CONFIG |g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|^gnome_menu|#gnome_menu|g ; \
		 s|^icon|#icon|g'

.include <bsd.port.mk>
