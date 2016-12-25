# $FreeBSD$

PORTNAME=	arduino-core
PORTVERSION=	1.6.13
CATEGORIES=	devel
DIST_SUBDIR=	arduino

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Core board support for Arduino devices

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_PROJECT=	Arduino

STRIP=		# No stripping, uses Elf firmware

OPTIONS_DEFINE=	DOCS EXAMPLES SAMD
OPTIONS_SUB=	yes
.if make(makesum)
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}"
.endif

NO_BUILD=	yes
SAMD_DESC=	Core support for SAMD boards (Zero/MKR1000)
SAMD_GH_TUPLE=	arduino:ArduinoCore-samd:1.6.8:samd/hardware/arduino/samd
SAMD_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-hardware_arduino_samd_platform.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
ARDUINO_ARCH=	x86_64
.else
ARDUINO_ARCH=	${ARCH}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%ARCH%%|${ARDUINO_ARCH}|g' -e 's|%%OSREL%%|${OSREL:R}|g' ${WRKSRC}/hardware/package_index_bundled.json

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "hardware" ${STAGEDIR}${PREFIX}/arduino ${FIND_EXPR})

.include <bsd.port.post.mk>
