# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	aa
PORTVERSION=	56
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://moshier.net/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Self-contained ephemeris calculator

EXTRACT_BEFORE_ARGS=	-aqo

USE_ZIP=	yes
MAKEFILE=	makefile
ALL_TARGET=	aa
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -Wall"
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PORTDOCS=	read.me readme.404 Readme.FreeBSD
PORTDATA=	messier.cat orbit.cat star.cat
PLIST_FILES=	bin/aa etc/aa.ini.default

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		's|%%PREFIX%%|${PREFIX}|g ; s|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/kfiles.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aa ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/aa.ini ${PREFIX}/etc/aa.ini.default
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${PORTDATA:S|^|${WRKSRC}/|} ${DATADIR}
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${CAT} ${PKGMESSAGE} > ${WRKSRC}/Readme.FreeBSD
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
