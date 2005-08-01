# New ports collection makefile for:	e3
# Date created:		Tue 5 Dec 2000
# Whom:			joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=	e3
PORTVERSION=	2.60.2
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.sax.de/~adlibit/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/60/6/}

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	A full featured text editor written in assembler

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=	${WRKDIR}/${PORTNAME}-2.6.2

USE_GMAKE=	yes
MAKE_ARGS=	OS=FREEBSD
ONLY_FOR_ARCHS=	i386

MAN1=		e3.1
PLIST_FILES=	bin/e3 bin/e3em bin/e3ne bin/e3pi bin/e3vi bin/e3ws

.include <bsd.port.mk>
