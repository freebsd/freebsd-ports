# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/f/${PORTNAME}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		ogg.4:${PORTSDIR}/audio/libogg

.if defined(WITH_XMMS)
# We don't build with id3lib support, because of C++ related build
# problems.  Detection is disabled by patch-configure.
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/multimedia/xmms
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

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

INSTALLS_SHLIB=	yes
MAN1=		flac.1 metaflac.1

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

test: build
	@cd ${WRKSRC}; make check

.include <bsd.port.mk>
