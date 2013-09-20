# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-synce
CATEGORIES=	deskutils palm
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SynCE plugin for the OpenSync framework

RUN_DEPENDS=	sync-engine:${PORTSDIR}/palm/synce-sync-engine \
		${LOCALBASE}/lib/opensync-1.0/plugins/python-module.so:${PORTSDIR}/deskutils/libopensync-plugin-python-devel

MASTERDIR=	${.CURDIR}/../../palm/synce-sync-engine

CONFLICTS=	libopensync-plugin-synce-[0-9]*

ENGINE_VER=	3
PLUGINDIR=	lib/opensync-1.0/plugins

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
