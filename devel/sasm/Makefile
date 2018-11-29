# $FreeBSD$

PORTNAME=	SASM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Simple IDE for NASM, MASM, GAS and FASM assembly languages

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Dman95
USE_QT=		core gui network widgets buildtools_build
USE_GL=		gl

DATADIR=	${PREFIX}/share/sasm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PEFIX}/share|' ${WRKSRC}/BSD/share/applications/sasm.desktop

.include <bsd.port.mk>
