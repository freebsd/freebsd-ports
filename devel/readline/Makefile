# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	readline
PORTVERSION=	7.0.${PATCHLEVEL}
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

PATCHES=	1 2 3
PATCHLEVEL=	${PATCHES:O:[-1]}
.for patch in ${PATCHES}
PATCHFILES+=	${PORTNAME}${PORTVERSION:R:S|.||}-${patch:S|^|00|:C|.*(...)$|\1|}
.endfor

post-patch-TERMCAP-on:
	# Comment out "Requires.private: tinfo" line since we do not have tinfo.pc in base system.
	# See PR/223130 for details.
	@${REINPLACE_CMD} -e '/^Requires.private: tinfo/ s|^|#|' ${WRKSRC}/readline.pc.in
	@${REINPLACE_CMD} -e '/SHOBJ_LDFLAGS = / s| = |&-ltermcapw |' ${WRKSRC}/shlib/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhistory.so.7 ${STAGEDIR}${PREFIX}/lib/libreadline.so.7
	${INSTALL_DATA} ${WRKSRC}/readline.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
