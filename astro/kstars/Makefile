# New ports collection makefile for:	kstars
# Date created:				Thu Sep 13 16:00:55 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	kstars
PORTVERSION=	0.7
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

GNU_CONFIGURE=	yes
USE_KDELIBS_VER=	2
CONFIGURE_ENV=	KDEDIR="${LOCALBASE}"

pre-patch:
	@${PERL} -pi.orig -e 's|-ljpeg6b|-ljpeg|; \
		s|-O2||' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
