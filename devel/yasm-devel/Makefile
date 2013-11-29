# Created by: ijliao
# $FreeBSD$

PORTNAME=		yasm
PORTVERSION=		1.2.0.29
DISTVERSIONSUFFIX=	.g87c0
CATEGORIES=		devel lang
MASTER_SITES=		http://www.tortall.net/projects/yasm/snapshots/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${DISTVERSION}${DISTVERSIONSUFFIX}
PKGNAMESUFFIX=		-devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Complete rewrite of the NASM assembler (Development Snapshot)

LICENSE=	BSD

OPTIONS_DEFINE=	DEBUG NLS

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-python --disable-python-bindings

NLS_USES=		gettext iconv
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libiconv-prefix=${LOCALBASE} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--without-libiconv-prefix \
			--without-libintl-prefix

CONFLICTS_INSTALL=	yasm-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O[0-9]//g}
.endif

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
