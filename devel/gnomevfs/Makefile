# New ports collection makefile for:	gnomevfs
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs
PORTVERSION=	1.0.5
PORTREVISION=	8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs/1.0
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Virtual File System

USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix glib12 libxml gtk12 orbit gconf \
		gnomemimedata gnomelibs
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

.if exists(${LOCALBASE}/lib/libcdda_paranoia.a)
WITH_CDPARANOIA=	yes
.endif

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
PLIST_SUB+=	CDPARANOIA=""
.else
PLIST_SUB+=	CDPARANOIA="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name 'xml-i18n-*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|g'
	@${REINPLACE_CMD} -e 's|\%\%LOCALBASE\%\%|${LOCALBASE}|g' \
		${WRKSRC}/libgnomevfs/libcharset/Makefile.in

.include <bsd.port.mk>
