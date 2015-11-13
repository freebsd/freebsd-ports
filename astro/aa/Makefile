# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	aa
PORTVERSION=	56
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://moshier.net/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Self-contained ephemeris calculator

BROKEN=		Checksum mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

MAKEFILE=	makefile
USES=		dos2unix zip
ALL_TARGET=	aa
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -Wall"
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PORTDOCS=	read.me readme.404
PORTDATA=	messier.cat orbit.cat star.cat
PLIST_FILES=	bin/aa etc/aa.ini.default

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		's|%%PREFIX%%|${PREFIX}|g ; s|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/kfiles.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/aa.ini ${STAGEDIR}${PREFIX}/etc/aa.ini.default
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${PORTDATA:S|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
