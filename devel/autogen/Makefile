# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

USE_LIBTOOL=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

MAN1=	autogen.1 columns.1 getdefs.1

post-install:
	@${RM} ${PREFIX}/lib/libsnprintfv.la

.include <bsd.port.mk>
