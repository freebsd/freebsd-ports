# New ports collection makefile for: fracplanet
# Date created:		15 Sep 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	fracplanet
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive generator of planets and terrain

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	boost_program_options.4:${PORTSDIR}/devel/boost

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_GL=		yes
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}" \
		VERSION_NUMBER="${PORTVERSION}"

PORTDOCS=	fracplanet.htm fracplanet.css
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
