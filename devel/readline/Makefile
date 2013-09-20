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
MAN3=		readline.3 history.3

PATCHES=	1 2 3 4
.for p in ${PATCHES:S/^/00/}
PATCH_FILES+=	${PORTNAME}${PORTVERSION:R:S/.//}-${p:C/.*(...)$/\1/}
.endfor
PATCHLEVEL=	${PATCHES:Q:S/ /./g:E}

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-configure:
.if ${PORT_OPTIONS:MTERMCAP}
	${REINPLACE_CMD} "s/SHOBJ_LDFLAGS =/SHOBJ_LDFLAGS = -ltermcap/" ${WRKSRC}/shlib/Makefile.in
.endif

.include <bsd.port.mk>
