# ex:ts=8
# New ports collection makefile for:	rvm
# Date created:				Mar 15, 2004
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rvm
PORTVERSION=	1.07
CATEGORIES=	archivers
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	davide.italiano@gmail.com
COMMENT=	An archive manager that uses rsync to manage backups

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_LATEST_LINK=	yes

USE_GMAKE=	yes
USE_GCC=	4.6+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/rvm.conf \
		--enable-assume-stl-memory-exception
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}"

MAN1=		rvm.1
PLIST_FILES=	bin/rvm

.include <bsd.port.mk>
