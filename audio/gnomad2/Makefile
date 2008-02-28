# New ports collection makefile for:	gnomad2
# Date created:				3 December 2006
# Whom:					Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	gnomad2
PORTVERSION=	2.8.11
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pesho.petrov@gmail.com
COMMENT=	A program for the NOMAD Jukebox to handle jukebox communication

LIB_DEPENDS=	mtp:${PORTSDIR}/audio/libmtp \
		njb.6:${PORTSDIR}/audio/libnjb \
		id3tag.0:${PORTSDIR}/audio/libid3tag

MAN1=		gnomad2.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

USE_GMAKE=	yes
USE_GNOME=	libglade2 libgnomeui
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
