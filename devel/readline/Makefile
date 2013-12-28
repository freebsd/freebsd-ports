# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	6.2.${PATCHLEVEL}
CATEGORIES=	devel
MASTER_SITES=	GNU \
		ftp://ftp.cwru.edu/pub/bash/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-patches

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Library for editing command lines as they are typed

LICENSE=	GPLv3

OPTIONS_DEFINE=	TERMCAP
OPTIONS_DEFAULT=TERMCAP
TERMCAP_DESC=	Link against libtermcap

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		readline rluserman history

PATCHES=	1 2 3 4 5
.for p in ${PATCHES:S/^/00/}
PATCH_FILES+=	${PORTNAME}${PORTVERSION:R:S/.//}-${p:C/.*(...)$/\1/}
.endfor
PATCHLEVEL=	${PATCHES:Q:S/ /./g:E}

.include <bsd.port.options.mk>

pre-configure:
.if ${PORT_OPTIONS:MTERMCAP}
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libreadline.so.6 \
		${STAGEDIR}${PREFIX}/lib/libhistory.so.6

.include <bsd.port.mk>
