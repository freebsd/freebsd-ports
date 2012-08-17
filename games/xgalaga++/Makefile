# New Ports collection makefile for:	xgalaga++
# Date created:		2012-04-20
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	xgalaga++
PORTVERSION=	0.8.3
CATEGORIES=	games
MASTER_SITES=	http://marc.mongenet.ch/OSS/XGalaga/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A classic single screen vertical shoot em up

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
USE_XORG=	x11 xpm
MAN6=		xgalaga++.6x

SUB_FILES=	pkg-install

PLIST_FILES=	bin/xgalaga++

PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^CXX =/ d; s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6
	${CHOWN} :games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} g+s  ${PREFIX}/bin/${PORTNAME}

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
