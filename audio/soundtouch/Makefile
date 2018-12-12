# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soundtouch
PORTVERSION=	1.9.2
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Open-source audio processing library

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USES=			autoreconf libtool pathfix

OPTIONS_DEFINE=	INTEGER_SAMPLES DOCS OPENMP
OPTIONS_DEFAULT=	${MACHINE_CPU:Msoftfp:C/.+/INTEGER_SAMPLES/}
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MSSE}

INTEGER_SAMPLES_DESC=	Use integer sample format
INTEGER_SAMPLES_CONFIGURE_ENABLE=	integer-samples
OPENMP_CONFIGURE_ENABLE=openmp
OPENMP_USES=		compiler:gcc-c++11-lib
SSE_CONFIGURE_ENABLE=	x86-optimizations
SSE_USES=		compiler:c++11-lang

post-patch:
	@${REINPLACE_CMD} -e \
		'/^dist_doc_DATA/s|COPYING.TXT||' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		's|^INCLUDES|AM_CPPFLAGS| ; \
		 s|$$(prefix)/doc|$$(datadir)/doc|' \
		${WRKSRC}/config/am_include.mk
.for i in SoundStretch SoundTouch
	@${REINPLACE_CMD} -e \
		's|-O[0-9]||;s|-fcheck-new||' \
		${WRKSRC}/source/${i}/Makefile.am
.endfor

.include <bsd.port.mk>
