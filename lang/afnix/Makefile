# ex:ts=8
# New ports collection makefile for:	aleph
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	afnix
PORTVERSION=	1.0.3
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S,.,-,g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	A multi-threaded functional programming language

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVER=${PORTVERSION:R}

MAN1=	afnix.1 axc.1 axd.1 axl.1

.include <bsd.port.pre.mk>

do-configure:
	@${WRKSRC}/cnf/bin/${PORTNAME}-setup -o

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
