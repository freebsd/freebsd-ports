# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-synce
CATEGORIES=	deskutils palm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SynCE plugin for the OpenSync framework

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

RUN_DEPENDS=	sync-engine:${PORTSDIR}/palm/synce-sync-engine \
		${LOCALBASE}/lib/opensync/plugins/python_module.so:${PORTSDIR}/deskutils/libopensync-plugin-python

MASTERDIR=	${.CURDIR}/../../palm/synce-sync-engine

CONFLICTS=	libopensync-plugin-synce-devel-[0-9]*

ENGINE_VER=	2
PLUGINDIR=	lib/opensync/python-plugins

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
