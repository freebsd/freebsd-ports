PORTNAME=	zydis
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast and lightweight x86/x86-64 disassembler library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	see definitions in include/Zycore/Defines.h

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	zyantific
GH_PROJECT=	zydis

GH_TUPLE=	zyantific:zycore-c:273e26a:zydis/dependencies/zycore

.include <bsd.port.mk>
