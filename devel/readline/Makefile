# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	8.0.${PATCHLEVEL}
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	GNU/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-patches

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for editing command lines as they are typed

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		history readline rluserman
PORTDOCS=	CHANGES INSTALL README

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}
CPE_UPDATE=	${PATCHLEVEL}

OPTIONS_DEFINE=	DOCS

PATCHES=	1
PATCHLEVEL=	${PATCHES:O:[-1]}
#PATCHLEVEL=	0
.for patch in ${PATCHES}
PATCHFILES+=	${PORTNAME}${PORTVERSION:R:S|.||}-${patch:S|^|00|:S|.*(...)$|\1|}
.endfor

post-patch:
.if exists(/usr/lib/libtermcapw.so)
	@${REINPLACE_CMD} 's|-ltermcap|-ltermcapw|g' ${WRKSRC}/configure
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhistory.so.8.0 ${STAGEDIR}${PREFIX}/lib/libreadline.so.8.0

.include <bsd.port.mk>
