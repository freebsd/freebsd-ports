# Ports collection makefile for:	delta
# Date created:			2012-07-09
# Whom:				eadler
#
# $FreeBSD$
#

PORTNAME=	delta
PORTVERSION=	2006.08.03
CATEGORIES=	devel
MASTER_SITES=	http://delta.tigris.org/files/documents/3103/33566/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Heuristically minimizes interesting files

LICENSE=	BSD

FETCH_DEPENDS=	wget:${PORTSDIR}/ftp/wget

FETCH_CMD=	${LOCALBASE}/bin/wget
FETCH_ARGS=	--quiet

PLIST_FILES=	bin/delta bin/multidelta bin/topformflat

USE_GMAKE=	yes

do-install:
.for file in delta multidelta
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/topformflat ${PREFIX}/bin

.include <bsd.port.mk>
