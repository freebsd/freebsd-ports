# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfoo
PORTVERSION=	1.0.6
CATEGORIES=	archivers
MASTER_SITES=	CENKES
#http://obsoleet.org/code/unfoo/unfoo-1.0.6.sh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny sh(1) wrapper to simplify decompression of files

RUN_DEPENDS=	unace:${PORTSDIR}/archivers/unace \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		7z:${PORTSDIR}/archivers/p7zip

NO_BUILD=	yes
USES=		tar:bzip2
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '1s|/.*|/bin/sh|;s|==|=|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
