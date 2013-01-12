# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	libelf
PORTVERSION=	0.8.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.mr511.de/software/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	rodrigo@bebik.net
COMMENT=	A public ELF file access library similar to libelf(3) in Solaris

OPTIONS_DEFINE=	EXTENDED NLS SANITY
OPTIONS_DEFAULT=	EXTENDED SANITY

EXTENDED_DESC=	ELF format extensions
SANITY_DESC=	Avoid loading invalid ELF files

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared --disable-compat
USE_LDCONFIG=	yes

NOMAN=		defined

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=	yes
PLIST_SUB+=	GETTEXT=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if ${PORT_OPTIONS:MEXTENDED}
CONFIGURE_ARGS+=	--enable-extended-format
.else
CONFIGURE_ARGS+=	--disable-extended-format
.endif

.if ${PORT_OPTIONS:MSANITY}
CONFIGURE_ARGS+=	--enable-sanity-checks
.else
CONFIGURE_ARGS+=	--disable-sanity-checks
.endif

.include <bsd.port.mk>
