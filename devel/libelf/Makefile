PORTNAME=	libelf
DISTVERSION=	0.8.13
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	NETBSD

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Public ELF file access library similar to libelf(3) in Solaris

LICENSE=	LGPL20

USES=		desthack pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--enable-shared --disable-compat

CONFLICTS_INSTALL=	elfutils

OPTIONS_DEFINE=		EXTENDED NLS SANITY
OPTIONS_DEFAULT=	EXTENDED SANITY

EXTENDED_DESC=		ELF format extensions
SANITY_DESC=		Avoid loading invalid ELF files

EXTENDED_CONFIGURE_ENABLE=	extended-format
NLS_USES=			gettext localbase:ldflags
NLS_CONFIGURE_ENABLE=		nls
NLS_LDFLAGS=			-lintl
SANITY_CONFIGURE_ENABLE=	sanity-checks

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	GETTEXT=""
.else
PLIST_SUB+=	GETTEXT="@comment "
.endif

.include <bsd.port.mk>
