# $FreeBSD$

PORTNAME=	jbig2dec
PORTVERSION=	0.11
PORTREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decoder implementation of the JBIG2 image compression format

LICENSE=	GPLv3

USES=		tar:xz libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PNG TESTS
OPTIONS_DEFAULT=	PNG

TESTS_DESC=	Download and use test-images for post-build testing

EXTRACT_AFTER_ARGS+=	--exclude sha1.h --exclude 'getopt*'

PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ON=	--with-libpng=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
MASTER_SITES+=	http://jbig2dec.sourceforge.net/ubc/:tests
DISTFILES+=	jb2streams.zip:tests
USES+=		python:build
KNOWN_BAD_JB2S=	042_11 042_13 042_14 042_24 042_25 amb_1 amb_2

post-extract:
	@${MKDIR} ${WRKDIR}/ubc
	@${TAR} -C ${WRKDIR}/ubc/ -xpf ${DISTDIR}/jb2streams.zip \
		${KNOWN_BAD_JB2S:S/$/.jb2/:S/^/--exclude /}
.else
EXTRA_PATCHES=	${FILESDIR}/simpler-test-patch
.endif

post-patch:
.if ${PORT_OPTIONS:MPNG}
	@${REINPLACE_CMD} 's/png_check_sig/png_sig_cmp/g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -E 's|SHA1_Final\( *([^,]+), *([^\)]+)\)|SHA1_Final(\2, \1)|' \
		${WRKSRC}/jbig2dec.c ${WRKSRC}/sha1.c
	@${REINPLACE_CMD} -e '1 s|${SETENV} python|${PYTHON_CMD}|' \
		${WRKSRC}/test_jbig2dec.py

test check regression-test:
	${MAKE} -C ${WRKSRC} check-TESTS

post-build:	test

.include <bsd.port.mk>
