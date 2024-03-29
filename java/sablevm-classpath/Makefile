PORTNAME=	sablevm-classpath
PORTVERSION=	1.13
PORTREVISION=	13
CATEGORIES=	java devel
MASTER_SITES=	SF/sablevm/sablevm/${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Classpath of SableVM
WWW=		http://www.sablevm.org/

LICENSE=	GPLv2

DEPRECATED=	Only user in tree is java/sablevm which is deprecated
EXPIRATION_DATE=2024-03-31

BROKEN_aarch64=		Fails to configure: Endianess not declared
BROKEN_riscv64=		Fails to configure: Endianess not declared

BUILD_DEPENDS=	jikes:java/jikes

USES=		gmake libtool localbase pkgconfig xorg
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_XORG=	x11 ice xtst sm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-dssi

INSTALL_TARGET=	install-strip

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	CAIRO GTK2 ZIP
OPTIONS_DEFAULT=GTK2 ZIP
OPTIONS_SUB=	yes

CAIRO_DESC=	Use Cairo based Graphics2D
GTK2_DESC=	Enable Gtk+ AWT peer
ZIP_DESC=	Compress class library

CAIRO_IMPLIES=	GTK2
CAIRO_CONFIGURE_ON=	--enable-gtk-cairo
GTK2_USES=			gnome
GTK2_USE=	GNOME=gtk20
GTK2_CONFIGURE_OFF=	--disable-gtk-peer
ZIP_BUILD_DEPENDS=		zip:archivers/zip
ZIP_CONFIGURE_ON=	--with-compressed-classes=zip
ZIP_CONFIGURE_OFF=	--with-compressed-classes=no
ZIP_PLIST_SUB=		WITHOUT_ZIP="@comment " WITH_ZIP=""
ZIP_PLIST_SUB_OFF=		WITHOUT_ZIP="" WITH_ZIP="@comment "

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${CP} -f ${WRKSRC}/resource/java/security/classpath.security \
	    ${WRKSRC}/resource/java/security/SableVM.security

.include <bsd.port.mk>
