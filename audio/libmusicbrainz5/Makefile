# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz
PORTVERSION=	2.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2nd generation incarnation of the CD Index - audio metadata

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g;s|^CPPFLAGS=|#CPPFLAGS=|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/pkgconfig|data/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${CAT} /dev/null > ${WRKSRC}/missing

.include <bsd.port.mk>
