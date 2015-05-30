# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfoo
PORTVERSION=	1.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny sh(1) wrapper to simplify decompression of files

RUN_DEPENDS=	unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		7z:${PORTSDIR}/archivers/p7zip

USE_GITHUB=	yes
GH_ACCOUNT=	vitaminmoo

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|;s|==|=|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
