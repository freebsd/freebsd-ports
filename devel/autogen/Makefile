# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.2.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure snprintfv/configure
CONFIGURE_TARGET=	# none
INSTALLS_SHLIB=	yes

MAN1=	autogen.1 columns.1 getdefs.1

pre-patch:
	@${PERL} -pi -e 's|values.h ||g' ${WRKSRC}/snprintfv/configure

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/libtool
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/snprintfv/libtool

.include <bsd.port.mk>
