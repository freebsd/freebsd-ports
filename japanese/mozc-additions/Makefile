# New ports collection makefile for:	mozc-additions
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc-additions
PORTVERSION=	1.3.911.102
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	daichi

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Additional tools and images for Mozc Japanese Input Method

NO_BUILD=	yes
LOCALBASE_REPLACE_FILES= \
		Makefile

post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
		${LOCALBASE_REPLACE_FILES}

.include <bsd.port.mk>
