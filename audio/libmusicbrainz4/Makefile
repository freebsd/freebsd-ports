# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2nd generation incarnation of the CD Index - audio metadata

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-version-info 2:|-version-info 3:|g' \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
