# New ports collection makefile for:	libopensync-plugin-synce
# Date created:				27 September 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-synce
CATEGORIES=	deskutils palm

MAINTAINER=	avl@FreeBSD.org
COMMENT=	SynCE plugin for the OpenSync framework

RUN_DEPENDS=	sync-engine:${PORTSDIR}/palm/synce-sync-engine \
		${LOCALBASE}/lib/opensync/plugins/python_module.so:${PORTSDIR}/deskutils/libopensync-plugin-python

MASTERDIR=	${.CURDIR}/../../palm/synce-sync-engine

CONFLICTS=	libopensync-plugin-synce-devel-[0-9]*

ENGINE_VER=	2
PLUGINDIR=	lib/opensync/python-plugins

.include "${MASTERDIR}/Makefile"
