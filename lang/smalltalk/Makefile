# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	1.95.7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO='makeinfo --no-split'
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		gst.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/gst.info*

pre-patch:
	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's| -release \$$\(VERSION\)| -avoid-version|g'
	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/ltdl/ltdl.c

.include <bsd.port.mk>
