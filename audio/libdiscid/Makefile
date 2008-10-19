# New ports collection makefile for:	libdiscid
# Date created:				2008-03-19
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdiscid
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library for creating MusicBrainz DiscIDs

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|\$$(libdir)/pkgconfig|\$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
