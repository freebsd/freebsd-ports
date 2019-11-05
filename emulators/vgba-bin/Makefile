# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	vgba
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/VGBA/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGBA${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator of Nintendo GameBoy Advance(TM)

LIB_DEPENDS=	libc.so.5:misc/compat5x \
		libm.so.2:misc/compat4x

ONLY_FOR_ARCHS=	i386
NO_BUILD=	no
NO_WRKSUBDIR=	no
USES=		xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/vgba
PORTDOCS=	VGBA.html

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vgba ${STAGEDIR}${PREFIX}/bin
	ldd ${WRKSRC}/vgba

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/VGBA.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
