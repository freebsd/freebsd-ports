# New ports collection makefile for:	fte
# Date created:				8 May 2000
# Whom:					gelf
#
# $FreeBSD$
#

PORTNAME=		fte
PORTVERSION=		20050108
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=		${PORTNAME}-${PORTVERSION:S/./b/}-src.zip \
			${PORTNAME}-${PORTVERSION:S/./b/}-common.zip

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A full-featured text editor for X11

WRKSRC=			${WRKDIR}/fte

USE_XLIB=		yes
USE_ZIP=		yes
USE_PERL5_BUILD=	yes

.include <bsd.port.mk>
