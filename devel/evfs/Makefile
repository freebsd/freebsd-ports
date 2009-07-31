# New ports collection makefile for:	evfs
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	evfs
PORTVERSION=	20080223
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An extensible virtual file system library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget libxml2
USE_EFL=	ecore eet efreet evas
USE_EFL_ECORE=	desktop ipc
USE_LDCONFIG=	yes
USE_SQLITE=	3

OPTIONS=	SAMBA	"Build samba plugin" off \
		FTP	"Build FTP plugin" on \
		TAGLIB	"Use taglib for audio metadata extraction" on \
		XTRACT "Enable extended metadata extraction via libextractor" on

.include <bsd.port.pre.mk>

.if defined(WITH_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
PLIST_SUB+=	SAMBA="@comment "
CONFIGURE_ARGS+=--disable-samba
.endif

.if !defined(WITHOUT_FTP) || exists(${LOCALBASE}/lib/libcurl.so.4)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
PLIST_SUB+=	FTP=""
.else
PLIST_SUB+=	FTP="@comment "
.endif

.if !defined(WITHOUT_TAGLIB) || exists(${LOCALBASE}/lib/libtag.so.6)
LIB_DEPENDS+=	tag.6:${PORTSDIR}/audio/taglib
PLIST_SUB+=	TAGLIB=""
.else
PLIST_SUB+=	TAGLIB="@comment "
.endif

.if !defined(WITHOUT_XTRACT) || exists(${LOCALBASE}/lib/libextractor.so.2)
LIB_DEPENDS+=	extractor.2:${PORTSDIR}/textproc/libextractor
PLIST_SUB+=	XTRACT=""
.else
PLIST_SUB+=	XTRACT="@comment "
.endif

.include <bsd.port.post.mk>
