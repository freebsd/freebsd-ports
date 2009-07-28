# New ports collection makefile for: fracplanet
# Date created:		15 Sep 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	fracplanet
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive generator of planets and terrain

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	boost_program_options.4:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
USE_GL=		glu
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}" \
		VERSION_NUMBER="${PORTVERSION}"

MAN1=		${PORTNAME}.1
PORTDOCS=	${PORTNAME}.css ${PORTNAME}.htm
PLIST_FILES=	bin/${PORTNAME}

BASH?=		${LOCALBASE}/bin/bash
QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

post-patch:
.for file in VERSION configure
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!${BASH}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BASH} ./configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
