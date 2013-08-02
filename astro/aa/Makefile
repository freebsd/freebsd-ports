# New ports collection makefile for:	aa
# Date created:			11 August 2006
# Whom:				Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	aa
PORTVERSION=	56
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://moshier.net/ \
		http://www.mirrorservice.org/sites/www.moshier.net/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Self-contained ephemeris calculator

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
EXTRACT_BEFORE_ARGS=	-aqo

USE_ZIP=	yes
MAKEFILE=	makefile
ALL_TARGET=	aa

SUB_FILES=	pkg-message

PORTDOCS=	read.me readme.404 Readme.FreeBSD
PORTDATA=	messier.cat orbit.cat star.cat
PLIST_FILES=	bin/aa etc/aa.ini.default

post-patch:
	@${REINPLACE_CMD} \
		's|%%PREFIX%%|${PREFIX}|g ; s|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/kfiles.c
	@${REINPLACE_CMD} 's|CFLAGS=  -O2|CFLAGS+=| ; s|CC=|CC?=|' ${WRKSRC}/makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/aa ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/aa.ini ${PREFIX}/etc/aa.ini.default
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
.for i in ${PORTDATA}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE} > ${WRKSRC}/Readme.FreeBSD
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
