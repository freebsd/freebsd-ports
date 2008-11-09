# New ports collection makefile for:	libopensync-plugin-syncml
# Date created:				6 November 2008
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-syncml
PORTVERSION=	0.22
CATEGORIES=	deskutils palm comms
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	This plugin allows to be synchronized against SyncML capable devices

LIB_DEPENDS=	opensync.0:${PORTSDIR}/devel/libopensync022 syncml.0:${PORTSDIR}/comms/libsyncml

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
