# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ecru
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://novel.evilcoder.org/ecru/files/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Flexible command line LiveJournal client

DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=	2013-12-01

LIB_DEPENDS=	xmlrpc.3:${PORTSDIR}/net/xmlrpc-c \
		config++.10:${PORTSDIR}/devel/libconfig \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm

USES=			pkgconfig
USE_PYTHON_BUILD=	yes
USE_BZIP2=		yes
MANCOMPRESSED=		yes
USE_LDCONFIG=		yes

MAN1=	ecru-config.1 ecru-delete.1 ecru-edit.1 \
	ecru-info.1 ecru-list.1 ecru-post.1

NO_STAGE=	yes
do-configure:
	@cd ${WRKSRC} && ./waf configure --prefix="${PREFIX}"

do-build:
	@cd ${WRKSRC} && ./waf build

do-install:
	@cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
