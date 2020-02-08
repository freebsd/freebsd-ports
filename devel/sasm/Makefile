# $FreeBSD$

PORTNAME=	SASM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.1
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Simple IDE for NASM, MASM, GAS and FASM assembly languages

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Dman95
USE_GL=		gl
USE_QT=		core gui network widgets buildtools_build

DATADIR=	${PREFIX}/share/sasm
DOCSDIR=	${PREFIX}/share/doc/sasm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/BSD/share/applications/sasm.desktop

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/sasm

.include <bsd.port.mk>
