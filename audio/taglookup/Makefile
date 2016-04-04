# Created by: Alex Allan <alex@kamaz.org.uk>
# $FreeBSD$

PORTNAME=	taglookup
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.kamaz.org.uk/taglookup/

MAINTAINER=	alex@kamaz.org.uk
COMMENT=	Utility for tagging groups of audio files using CDDB

LIB_DEPENDS=	libcddb.so:audio/libcddb \
		libtag.so:audio/taglib

USES=		pkgconfig tar:tgz

PLIST_FILES=	bin/taglookup \
		man/man1/taglookup.1.gz

.include <bsd.port.mk>
