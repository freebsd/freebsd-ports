# New ports collection makefile for:	libdiscid
# Date created:				2008-03-19
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdiscid
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://users.musicbrainz.org/~matt/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library for creating MusicBrainz DiscIDs

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack gnomehack
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
