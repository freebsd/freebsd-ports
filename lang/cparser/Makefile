# New ports collection makefile for: libFIRM
# Date created:         22 Nov 2008
# Whom:                 Christoph Mallon <christoph.mallon@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cparser
PORTVERSION=	0.9.6
CATEGORIES=	lang devel
MASTER_SITES=	http://www.info.uni-karlsruhe.de/software/libfirm/

MAINTAINER=	christoph.mallon@gmx.de
COMMENT=	A C99 compiler using libFIRM as backend

RUN_DEPENDS=	${LOCALBASE}/lib/libfirm.a:${PORTSDIR}/devel/libfirm
LIB_DEPENDS=	firm.0:${PORTSDIR}/devel/libfirm

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/cparser

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/cparser ${PREFIX}/bin

.include <bsd.port.post.mk>
