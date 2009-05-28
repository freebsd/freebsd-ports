# New ports collection makefile for:	libopensync-plugin-synce-devel
# Date created:				27 September 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-synce
CATEGORIES=	deskutils palm
PKGNAMESUFFIX=	-devel

MAINTAINER=	avl@FreeBSD.org
COMMENT=	SynCE plugin for the OpenSync framework

RUN_DEPENDS=	sync-engine:${PORTSDIR}/palm/synce-sync-engine \
		${LOCALBASE}/lib/opensync-1.0/plugins/python-module.so:${PORTSDIR}/deskutils/libopensync-plugin-python-devel

MASTERDIR=	${.CURDIR}/../../palm/synce-sync-engine

CONFLICTS=	libopensync-plugin-synce-[0-9]*

ENGINE_VER=	3
PLUGINDIR=	lib/opensync-1.0/plugins

.include "${MASTERDIR}/Makefile"
