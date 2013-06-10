# Created by:	Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-vfs
PORTVERSION=	1.0.5
PORTREVISION=	17
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Virtual File System

DEPRECATED=	No more depend on, No more supported upstream
EXPIRATION_DATE=	2013-07-10

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix glib12 libxml gtk12 orbit gconf gnomemimedata \
		gnomelibs
USES=		gettext iconv pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

LATEST_LINK=	gnome-vfs1

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
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
