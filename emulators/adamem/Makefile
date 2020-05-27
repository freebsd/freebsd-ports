# Created by: Jeremy Karlson
# $FreeBSD$

PORTNAME=	adamem
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/~dekogel/files/coleco/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Coleco ADAM and ColecoVision emulator

BROKEN_aarch64=		fails to build: regparm is not valid on this platform
BROKEN_armv6=		fails to build: regparm is not valid on this platform
BROKEN_armv7=		fails to build: regparm is not valid on this platform

NO_WRKSUBDIR=	yes
USES=		xorg
USE_XORG=	sm x11 xau xext xfixes xi xrandr

MAKE_ARGS=	CC="${CC}" LD="${CC}"
ALL_TARGET=	x

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/ADAMEm.c \
		${WRKSRC}/Coleco.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adamem ${STAGEDIR}${PREFIX}/bin
	${LN} -s adamem ${STAGEDIR}${PREFIX}/bin/cvem
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in adamem.snd OS7.rom WP.rom EOS.rom
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/adamem.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
