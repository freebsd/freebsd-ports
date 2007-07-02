# New ports collection makefile for:	p5-Algorithm-Cluster
# Date created:				Fri May 21 15:21:09 CST 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Cluster
PORTVERSION=	1.36
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A perl interface to C clustering library

PERL_CONFIGURE=	yes

MAN3=		Algorithm::Cluster.3

post-patch:
		@${REINPLACE_CMD} -e  \
		"s|${PORTNAME}|Algorithm::Cluster|" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
