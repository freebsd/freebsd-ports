# New ports collection makefile for:	FINE
# Date created:			17 August 1999
# Whom:				Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fine
PORTVERSION=	2.4
CATEGORIES=	editors
MASTER_SITES=	http://www.lrv.fri.uni-lj.si/~bojank/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	kde@freebsd.org

NO_WRKSUBDIR=	yes

USE_QT_VER=	2
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" MOC="${MOC}" LIBQT="-l${QTNAME}" \
		QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fine ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.template ${DATADIR}

.include <bsd.port.post.mk>
