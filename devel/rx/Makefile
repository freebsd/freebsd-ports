# New ports collection makefile for:	rx
# Date created:				1 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	rx
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Replacement for the GNU regex library

EXTRACT_AFTER_ARGS=	| ${TAR} -Pxf -

GNU_CONFIGURE=	yes

INFO=		rx

PLIST_FILES=	include/rxposix.h \
		lib/librx.a

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/rx.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
