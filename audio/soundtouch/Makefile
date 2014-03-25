# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soundtouch
PORTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Open-source audio processing library

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I config/m4
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

USES=			pathfix
PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=	INTEGER_SAMPLES DOCS
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE

INTEGER_SAMPLES_DESC=	Use integer sample format
INTEGER_SAMPLES_CONFIGURE_ENABLE=	integer-samples
SSE_CONFIGURE_ENABLE=	x86-optimizations

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pkgdoc_DATA/s|COPYING.TXT||' \
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
