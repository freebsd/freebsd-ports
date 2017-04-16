# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	6.3.${PATCHLEVEL}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	GNU/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-patches

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for editing command lines as they are typed

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	TERMCAP DOCS
OPTIONS_DEFAULT=TERMCAP
TERMCAP_DESC=	Link against libtermcap

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		cpe

INFO=		history readline rluserman
PORTDOCS=	CHANGES INSTALL README

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}
CPE_UPDATE=	${PATCHLEVEL}

PATCHES=	1 2 3 4 5 6 7 8
PATCHLEVEL=	${PATCHES:O:[-1]}
.for patch in ${PATCHES}
PATCHFILES+=	${PORTNAME}${PORTVERSION:R:S|.||}-${patch:S|^|00|:S|.*(...)$|\1|}
.endfor

post-patch-TERMCAP-on:
	@${REINPLACE_CMD} -e '/SHOBJ_LDFLAGS = / s| = |&-ltermcap |' ${WRKSRC}/shlib/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhistory.so.6 ${STAGEDIR}${PREFIX}/lib/libreadline.so.6

.include <bsd.port.mk>
