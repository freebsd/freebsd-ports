# ex:ts=8
# Ports collection Makefile for:	rvm
# Date created:			Mar 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rvm
PORTVERSION=	0.80.2.a
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/-alpha/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An archive manager that uses rsync to manage backups

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/rvm.conf

MAN1=		rvm.1
PLIST_FILES=	bin/rvm

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500034
CXXFLAGS+=	-O0
.endif

.include <bsd.port.post.mk>
