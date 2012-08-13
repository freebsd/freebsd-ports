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
COMMENT=	An open-source audio processing library

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

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON="uses -msse2 directive to CC"

post-patch:
	@${REINPLACE_CMD} -E 's|-O3 ?||' \
		${WRKSRC}/source/SoundStretch/Makefile.am \
		${WRKSRC}/source/SoundTouch/Makefile.am

run-autotools:	# see ${WRKSRC}/bootstrap for reference
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} \
		AUTOMAKE="${AUTOMAKE} --add-missing --foreign --copy" \
		${AUTORECONF} -fisv)

.include <bsd.port.mk>
