# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg

USE_ICONV=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--target=${ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-sse \
		--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}"
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include" \
		ac_cv_path_XMMS_CONFIG=no

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

INSTALLS_SHLIB=	yes
MAN1=		flac.1 metaflac.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

post-build:
	${REINPLACE_CMD} 's:%%PREFIX%%:${PREFIX}:' ${WRKSRC}/man/flac.1

test: build
	@cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
