# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	ae_fonts1_ttf
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	SF/arabeyes/Fonts/ae_fonts
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of TrueType Arabic fonts

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ae_fonts1-${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	AAHS AGA FS KASR MCS SHMOOKH
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

AAHS_DESC=	Install the AAHS font set
AGA_DESC=	Install the AGA font set
FS_DESC=	Install the FS font set
KASR_DESC=	Install the Kasr font set
MCS_DESC=	Install the MCS font set
SHMOOKH_DESC=	Install the Shmookh font set

.include <bsd.port.options.mk>

.for font in AAHS AGA FS MCS
.  if ${PORT_OPTIONS:M${font}}
FONTS+=	${font}
.  endif
.endfor

.for font in KASR SHMOOKH
.  if ${PORT_OPTIONS:M${font}}
FONTS+=	${font:C/(.).*/\1/}${font:L:C/.//}
.  endif
.endfor

do-build:
.for font in ${FONTS}
	cd ${WRKSRC} && ttmkfdir -c -d ${WRKSRC}/${font} > \
		${WRKSRC}/${font}/fonts.dir
.endfor

do-install:
.for font in ${FONTS}
	${MKDIR} ${PREFIX}/lib/X11/fonts/ae_fonts1/${font}
	${INSTALL_DATA} ${WRKSRC}/${font}/* \
		${PREFIX}/lib/X11/fonts/ae_fonts1/${font}
.endfor

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
