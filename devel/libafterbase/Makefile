# ex:ts=8
# New ports collection makefile for:	libAfterBase
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterbase
PORTVERSION=	0.91
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterBase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-sharedlibs --with-x
INSTALLS_SHLIB=	yes

post-patch:
	@find ${WRKSRC} -name '*.[ch]' | xargs ${PERL} -pi -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
