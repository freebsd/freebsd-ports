# New ports collection makefile for:	noegnud-data
# Date created:				7 April 2004
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	noegnud
PORTVERSION=	0.8.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-data
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The noeGNUd Data Files

NOEGNUDVERSION=	${PORTNAME}-0.8.0
DATADIR=	${PREFIX}/share/${NOEGNUDVERSION}
MAKE_ENV+=	DATADIR="${DATADIR}"
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
ALL_TARGET=	data
INSTALL_TARGET=	install_data

.include <bsd.port.mk>
