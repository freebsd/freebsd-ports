# New ports collection makefile for:	e3
# Date created:		Tue 5 Dec 2000
# Whom:			joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=	e3
PORTVERSION=	2.43
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.sax.de/~adlibit/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	A full featured text editor written in assembler

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
MAKE_ARGS=	OS=FREEBSD
ONLY_FOR_ARCHS=	i386

MAN1=		e3.1

.include <bsd.port.mk>
