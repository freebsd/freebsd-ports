# New ports collection makefile for:	doxygenfilter
# Date created:		Tue Oct 28 07:38:51 UTC 2008
# Whom:			Sergei Golyashov <svvord@spline-studio.ru>
#
# $FreeBSD$
#

PORTNAME=	doxygenfilter
PORTVERSION=	1.01
CATEGORIES=	devel
MASTER_SITES=	SF/bigsister/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	svvord@spline-studio.ru
COMMENT=	Input filter for Doxygen enabling support for Perl code documentation

RUN_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen

PERL_CONFIGURE=	yes

MAN3=		DoxyGen::Filter.3

.include <bsd.port.mk>
