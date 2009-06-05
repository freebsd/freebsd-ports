# New ports collection makefile for:	p5-Cdk
# Date created:				May 27th 2001
# Whom:	      				Chia-liang Kao <clkao@clkao.org>
#
# $FreeBSD$
#

PORTNAME=	Cdk
PORTVERSION=	4.9.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://dickey.his.com/cdk/
PKGNAMEPREFIX=	p5-
DISTNAME=	cdk-perl-20031210
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for Curses Development Kit

LIB_DEPENDS=	cdk.5:${PORTSDIR}/devel/cdk

PERL_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
