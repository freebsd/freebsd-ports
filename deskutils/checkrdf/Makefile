# New ports collection makefile for:   checkrdf
# Date created:        17 december 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkrdf
PORTVERSION=	30.5000
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	checkrdf

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	Xtract:${PORTSDIR}/textproc/hs-haxml

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

MAKE_ENV=	PREFIX=${PREFIX}
.if !exists(${PREFIX}/bin/nhc98)
MAKE_ENV+=	BUILD_WITH=GHC
.endif

MAN1=		checkrdf.1
MANCOMPRESSED=	yes

.if defined(NOPORTDOCS)
INSTALL_TARGET=install-bin install-rc install-man
.endif

.include <bsd.port.post.mk>
