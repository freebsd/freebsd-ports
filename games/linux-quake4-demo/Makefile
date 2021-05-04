# Created by: alepulver

PORTNAME=	quake4
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	IDSOFTWARE/${PORTNAME}/demo GENTOO
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}${PKGNAMESUFFIX}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 4 for Linux Demo

# Converted from NO_CDROM
LICENSE=	IDSOFTWARE
LICENSE_NAME=	IDSOFTWARE
LICENSE_TEXT=	Redistribution is limited, see license
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		linux
USE_LINUX=	sdl12
NO_WRKSUBDIR=	yes

Q4DIR=		lib/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	Q4DIR="${Q4DIR}"

do-extract:
	@cd ${WRKSRC} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
.for FILE in quake4 q4ded
	@${SED} \
		-e 's|@Q4DIR@|${PREFIX}/${Q4DIR}|' \
		-e 's|@APP@|${FILE}.x86|' \
		${FILESDIR}/run.sh.in > ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${Q4DIR}/q4base
.for FILE in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}-demo
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/${FILE}.x86 \
		${STAGEDIR}${PREFIX}/${Q4DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/q4base/* ${STAGEDIR}${PREFIX}/${Q4DIR}/q4base

.include <bsd.port.mk>
