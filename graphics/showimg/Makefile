# Created by: ijliao
# $FreeBSD$

PORTNAME=	showimg
PORTVERSION=	0.9.5
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/${PORTNAME}/download/${PORTVERSION}/ \
		http://vxj-se.lunar-linux.org/lunar/cache/

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Picture viewer designed to run under KDE 3.x

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_KDEBASE_VER=	3
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--disable-pgsql

OPTIONS_DEFINE=	KIPI KEXIF KEXIDB MYSQL
KIPI_DESC=	libkipi support
KEXIF_DESC=	kexif support
KEXIDB_DESC=	KexiDB/ShowimgDB support

OPTIONS_DEFAULT=	KIPI KEXIF KEXIDB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKIPI}
LIB_DEPENDS+=	kipi:${PORTSDIR}/graphics/libkipi
.else
CONFIGURE_ARGS+=--disable-libkipi
.endif

.if ${PORT_OPTIONS:MKEXIF}
LIB_DEPENDS+=	kexif:${PORTSDIR}/graphics/libkexif
.else
CONFIGURE_ARGS+=--without-kexif
.endif

.if ${PORT_OPTIONS:MKEXIDB) && {PORT_OPTIONS:MMYSQL}
PLIST_SUB+=	KEXIDB=""
.else
CONFIGURE_ARGS+=--without-showimgdb
PLIST_SUB+=	KEXIDB="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '347,365d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
