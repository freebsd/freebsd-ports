# New ports collection makefile for:	ecru
# Date created:				2008-12-13
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ecru
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://novel.evilcoder.org/ecru/files/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Flexible command line LiveJournal client

LIB_DEPENDS=	xmlrpc.9:${PORTSDIR}/net/xmlrpc-c \
		config++.9:${PORTSDIR}/devel/libconfig \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm

USE_PYTHON_BUILD=	yes
USE_BZIP2=		yes
MANCOMPRESSED=		yes
USE_LDCONFIG=		yes

MAN1=	ecru-config.1 ecru-delete.1 ecru-edit.1 \
	ecru-info.1 ecru-list.1 ecru-post.1

do-configure:
	@cd ${WRKSRC} && ./waf configure --prefix="${PREFIX}"

do-build:
	@cd ${WRKSRC} && ./waf build

do-install:
	@cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
