# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	1.95.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all optimize

MAN1=		gst.1

pre-patch:
	@${PERL} -pi -e 's| install-data-local||g' ${WRKSRC}/kernel/Makefile.in

pre-build:
	${RM} ${WRKSRC}/docs/gst.info*

post-install:
	@cd ${PREFIX}/share/gnu-smalltalk && ${PREFIX}/bin/gst -Vi dummyFile

.include <bsd.port.mk>
