# New ports collection makefile for:	p5-xmms2
# Date created:				05 Jul 2007
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	audio perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Bindings for XMMS2

LIB_DEPENDS+=	xmmsclient.4:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_PERL5=	yes

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	perl

.include "${MASTERDIR}/Makefile"
