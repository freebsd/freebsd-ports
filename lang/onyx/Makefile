# New ports collection Makefile for:	onyx
# Date created:		15 May 2001
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	onyx
PORTVERSION=	3.0.2
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Embeddable stack-based threaded interpreted language

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook
LIB_DEPENDS=	edit.5:${PORTSDIR}/devel/libedit

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libedit-prefix=${PREFIX}
INSTALLS_SHLIB=	yes

MAN1=		onyx.1
MANCOMPRESSED=	no

PLIST_SUB=	ONYX_VERSION=${PORTVERSION}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook install)

post-install:
	@strip ${PREFIX}/bin/onyx
	@cat ${PKGMESSAGE}

.include <bsd.port.mk>
