# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	vgb
PORTVERSION=	3.0
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/VGB/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGB${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo GameBoy(tm) emulator (closed binary version of vgb)

LIB_DEPENDS=	libc.so.5:misc/compat5x

IA32_BINARY_PORT=	yes
NO_BUILD=	no
NO_WRKSUBDIR=	no
USE_XORG=	x11 xext

PLIST_FILES=	bin/vgb
PORTDATA=	CART.GB
PORTDOCS=	VGB.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vgb ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CART.GB ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/VGB.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
