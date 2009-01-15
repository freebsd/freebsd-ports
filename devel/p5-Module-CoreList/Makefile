# New ports collection makefile for:	devel/p5-Module-CoreList
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-CoreList
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	See what modules shipped with versions of perl

PERL_CONFIGURE=	yes

MAN1=		corelist.1
MAN3=		Module::CoreList.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 5.00809
.undef MAN1
PLIST_SUB+=	PL_FILES="@comment "
pre-patch:
	@${PERL} -pi -e "s,'corelist',," ${WRKSRC}/Makefile.PL
.else
PLIST_SUB+=	PL_FILES=""
.endif

.include <bsd.port.post.mk>
