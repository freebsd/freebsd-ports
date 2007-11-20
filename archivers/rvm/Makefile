# ex:ts=8
# Ports collection Makefile for:	rvm
# Date created:			Mar 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rvm
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	rvm_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An archive manager that uses rsync to manage backups

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_LATEST_LINK=	yes

USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/rvm.conf
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}"

MAN1=		rvm.1
PLIST_FILES=	bin/rvm

.include <bsd.port.mk>
