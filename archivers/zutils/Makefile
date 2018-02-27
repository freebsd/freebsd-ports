# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	zutils
PORTVERSION=	1.7
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/zutils
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Utilities for searching in bzip2, gzip, lzip, and xz archives

LICENSE=	GPLv2

EXTRACT_DEPENDS=	lzip:archivers/lzip

INFO=		zutils

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} ; ${LOCALBASE}/bin/lzip -cd \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | ${TAR} -xf -)

post-patch:
	# Remove compiler hardcoded flags and use environment
	@${REINPLACE_CMD} '23,26d' ${WRKSRC}/configure

post-install:
	@-${RM} ${STAGEDIR}${PREFIX}/info/dir

.include <bsd.port.mk>
