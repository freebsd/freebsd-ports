# New ports collection makefile for:	keximdb
# Date created:				29 Apr 2006
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$

PORTNAME=		keximdb
PORTVERSION=		1.1.0
PORTREVISION=	5
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-1.6.3/src

MAINTAINER=		ports@FreeBSD.org
COMMENT=		MS Access import plugin for Kexi

DEPRECATED=	Depends on editors/koffice-kde3, which is scheduled for deletion
EXPIRATION_DATE=	2011-11-30

LIB_DEPENDS=		kexicore:${PORTSDIR}/editors/koffice-kde3

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes

.include <bsd.port.mk>
