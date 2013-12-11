# Created by: Alex Allan <alex@kamaz.org.uk>
# $FreeBSD$

PORTNAME=	taglookup
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.kamaz.org.uk/taglookup/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@kamaz.org.uk
COMMENT=	Utility for tagging groups of audio files using CDDB

LIB_DEPENDS=	libcddb.so:${PORTSDIR}/audio/libcddb \
		libtag.so:${PORTSDIR}/audio/taglib

USES=		pkgconfig
NO_STAGE=	yes

MAN1=		taglookup.1
PLIST_FILES=	bin/taglookup

.include <bsd.port.mk>
