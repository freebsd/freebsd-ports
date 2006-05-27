# New ports collection makefile for:	keximdb
# Date created:				29 Apr 2006
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$

PORTNAME=		keximdb
PORTVERSION=		1.0.1
CATEGORIES=		databases
MASTER_SITES=		http://martin.ellis.name/koffice/

MAINTAINER=		kde@FreeBSD.org
COMMENT=		MS Access import plugin for Kexi

LIB_DEPENDS=		kexicore:${PORTSDIR}/editors/koffice-kde3

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
