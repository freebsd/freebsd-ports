# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/converters/libiconv:extract
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		ogg.4:${PORTSDIR}/audio/libogg

.if defined(WITH_XMMS)
# id3lib is only used by the XMMS plugin
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS+=	id3-3.7.13:${PORTSDIR}/audio/id3lib \
		xmms.3:${PORTSDIR}/audio/xmms
CONFIGURE_ARGS+=--with-id3lib="${LOCALBASE}"
PLIST_SUB=	XMMS=""
.else
CONFIGURE_ENV+=	XMMS_CONFIG=/usr/bin/false	# must be absolute path
PLIST_SUB=	XMMS="@comment "
.endif

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

USE_LIBTOOL=	yes
CONFIGURE_TARGET= --target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS+=--enable-sse --enable-3dnow \
		--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}"
CONFIGURE_ENV=	CONFIG_SHELL=${SH}

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

INSTALLS_SHLIB=	yes
MAN1=		flac.1

# missing auxiliary script
post-extract:
	@${CP} `cd ${PORTSDIR}/converters/libiconv && make -V WRKSRC`/autoconf/config.rpath ${WRKSRC}

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

.include <bsd.port.mk>
