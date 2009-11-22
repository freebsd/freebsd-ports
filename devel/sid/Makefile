# New ports collection makefile for:	sid
# Date created:				29 May 2007
# Whom:					The Akuma Project
#
# $FreeBSD$
#

PORTNAME=	sid
PORTVERSION=	1.10.0
CATEGORIES=	devel
MASTER_SITES=	http://www.akumaproject.org/download/

MAINTAINER=	ports@akumaproject.org
COMMENT=	A LL(1) parser generator

CONFLICTS=	TenDRA-4.2*

INSTALL_TARGET=	install DESTDIR=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

USE_PERL5=	yes

MAN1=		sid.1
PLIST_FILES=	bin/sid

.include <bsd.port.mk>
