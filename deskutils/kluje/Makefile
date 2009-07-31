# New ports collection makefile for:	kluje
# Date created:				27 July 2003
# Whom:                                 Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	kluje
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE client for the popular online journal site LiveJournal

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
