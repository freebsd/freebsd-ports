# New ports collection makefile for:	SoundTouch
# Date created:				16 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soundtouch
DISTVERSION=	1.6.0
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source audio processing library

LICENSE=	LGPL21

USE_AUTOTOOLS=	autoconf automake libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared=yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		pkgdoc_DATA="${PORTDOCS}" pkgdocdir="${DOCSDIR}"
.if !defined(NOPORTDOCS)
PORTDOCS=	README.html
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	INTEGER_SAMPLES
INTEGER_SAMPLES_DESC=	Use integer sample format

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MINTEGER_SAMPLES}
CONFIGURE_ARGS+=	--enable-integer-samples
.endif

post-patch:
	@${REINPLACE_CMD} -E 's|-O3 ?||' \
		${WRKSRC}/source/SoundStretch/Makefile.am \
		${WRKSRC}/source/SoundTouch/Makefile.am
.if ${ARCH} != "i386" && ${ARCH} != "amd64" && ${ARCH} != "ia64"
	@${REINPLACE_CMD} '/AM_CXXFLAGS=/s|-msse2 ||' \
		${WRKSRC}/source/SoundTouch/Makefile.am
.endif

run-autotools:	# see ${WRKSRC}/bootstrap for reference
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} \
		AUTOMAKE="${AUTOMAKE} --add-missing --foreign --copy" \
		${AUTORECONF} -fisv)

.include <bsd.port.post.mk>
