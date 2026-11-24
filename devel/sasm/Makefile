PORTNAME=	SASM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.16.0
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://patch-diff.githubusercontent.com/raw/Dman95/SASM/pull/
PATCHFILES=	222.patch:-p1

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Simple IDE for NASM, MASM, GAS and FASM assembly languages
WWW=		https://dman95.github.io/SASM/english.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	Dman95
USE_GL=		gl
USE_QT=		5compat base

CONFLICTS_INSTALL=	fasm fasm-fpga

DATADIR=	${PREFIX}/share/sasm
DOCSDIR=	${PREFIX}/share/doc/sasm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|' ${WRKSRC}/BSD/share/applications/sasm.desktop

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/sasm

.include <bsd.port.mk>
