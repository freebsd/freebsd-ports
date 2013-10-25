# Created by: Yoshiaki Uchikawa
# $FreeBSD$

PORTNAME=	mikmod
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.raphnet.net/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Mod player which plays MTM, STM, XM, MOD, S3M, ULT, UNI, and IT mods

LICENSE=	GPLv2

LIB_DEPENDS=	mikmod:${PORTSDIR}/audio/libmikmod

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mikmod man/man1/mikmod.1.gz

PORTSCOUT=	skipv:3.3.0

OPTIONS_DEFINE=	COLOR

COLOR_DESC=	Build with color support

OPTIONS_DEFAULT=COLOR

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOLOR}
CONFIGURE_ARGS+=	--enable-color-interface
.endif

.include <bsd.port.mk>
