PORTNAME=	mastergear
DISTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/MG/
DISTNAME=	MG20-FreeBSD-80x86-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Master System and Game Gear emulator for X
WWW=		https://fms.komkon.org/MG/

# There is no mention of a license in the source code.
# License has to be acquired from the author.
LICENSE=NONE

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	is an i386 binary

LIB_DEPENDS=	libc.so.5:misc/compat5x

USES=		xorg tar:Z
USE_XORG=	x11 xext

STRIP=
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CART.ROM ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SF7000.ROM ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MG.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
