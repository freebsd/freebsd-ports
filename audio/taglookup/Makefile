# New ports collection makefile for:	taglookup
# Date created:				21 Oct 2007
# Whom:					Alex Allan <alex@kamaz.org.uk>
#
# $FreeBSD$
#

PORTNAME=	taglookup
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.kamaz.org.uk/taglookup/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@kamaz.org.uk
COMMENT=	Utility for tagging groups of audio files using CDDB

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb \
		tag.1:${PORTSDIR}/audio/taglib

MAN1=		taglookup.1
PLIST_FILES=	bin/taglookup

.include <bsd.port.mk>
