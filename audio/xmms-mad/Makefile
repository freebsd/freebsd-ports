# New ports collection makefile for:	xmms-mad
# Date created:				30 Aug 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-mad
PORTVERSION=	0.10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XMMS input plugin that uses libmad

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	lib/xmms/Input/libxmmsmad.so

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	cd ${WRKSRC}/src/.libs \
		&& ${INSTALL_DATA} libxmmsmad.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
