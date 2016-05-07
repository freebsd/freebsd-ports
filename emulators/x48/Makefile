# Created by: Eric L. Hernes <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x48
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	emulators math
MASTER_SITES=	SF/${PORTNAME}.berlios
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gxrom-r.bz2 sxrom-j.bz2
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	HP48 SX/GX graphic calculator emulator

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/fonts/misc/7x14B-ISO8859-1.pcf.gz:x11-fonts/font-misc-misc \
		${LOCALBASE}/share/fonts/75dpi/helvR12-ISO8859-1.pcf.gz:x11-fonts/font-adobe-75dpi

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-lutil
USES=		autoreconf gmake pkgconfig tar:bzip2
USE_XORG=	x11 xext xt
NO_WRKSUBDIR=	yes

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-extract: .SILENT
# Extract official HP ROM images for GX/SX
	${CP} ${_DISTDIR}/gxrom-r.bz2 ${WRKSRC} && ${BZIP2_CMD} \
		-d ${WRKSRC}/gxrom-r.bz2
	${CP} ${_DISTDIR}/sxrom-j.bz2 ${WRKSRC} && ${BZIP2_CMD} \
		-d ${WRKSRC}/sxrom-j.bz2

post-patch:
# Enable serial communication and prefer GX Revision R ROM by default
	@${REINPLACE_CMD} -e '/useSerial/s+False+True+ ; s+ttyS+cuau+ ; \
		s+rom\.dump+${DATADIR}/gxrom-r+' ${WRKSRC}/src/X48.ad.h
# Force correct type per what comment says
	@${REINPLACE_CMD} -e '/timer1/s+char+signed &+' ${WRKSRC}/src/hp48.h
# Fix the build against Clang (lots of warnings remain)
	@${REINPLACE_CMD} -e '1531s+char \*+void+' ${WRKSRC}/src/debugger.c
	@${REINPLACE_CMD} -e '698s+^+static +' ${WRKSRC}/src/emulate.c

do-install:
.for p in x48 dump2rom checkrom mkcard
	${INSTALL_PROGRAM} ${WRKSRC}/src/${p} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/??rom-? ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S+^+${WRKSRC}/+} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
