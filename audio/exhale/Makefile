# $FreeBSD$

PORTNAME=	exhale
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio

# Backport for MacOS compatibility
PATCH_SITES=	https://gitlab.com/ecodis/exhale/-/commit/
PATCHFILES=	4002bff2bf60a87731b42aa32743a910a0e017b8.patch:-p1

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Open source xHE-AAC (Extended HE-AAC/USAC) encoder

LICENSE=	EXHALE
LICENSE_NAME=	exhale Copyright License
LICENSE_FILE=	${WRKSRC}/include/License.htm
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake compiler:c++11-lang

USE_GITLAB=	yes
GL_ACCOUNT=	ecodis
GL_COMMIT=	c71ec4805a2cf0bdbc6968a5ef63d2dd326cf541

USE_LDCONFIG=	yes

PLIST_FILES=	bin/exhale \
		lib/libexhale.so

.include <bsd.port.mk>
