# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=	autogen.1 columns.1 getdefs.1

pre-patch:
	@${PERL} -pi -e 's|regcomp=no|regcomp=yes|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|values.h ||g' ${WRKSRC}/snprintfv/configure
	@${PERL} -pi -e 's|#include "proto.h"||g' ${WRKSRC}/getdefs/getdefs.h

.include <bsd.port.mk>
