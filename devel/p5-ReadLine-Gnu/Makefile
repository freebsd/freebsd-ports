# New ports collection makefile for:	p5-ReadLine-Gnu
# Date created:				19 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mph@FreeBSD.org
COMMENT=	Perl 5 module that allows Term::ReadLine to use GNU readline

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so)
CONFIGURE_ARGS+=--includedir=${LOCALBASE}/include
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

MAN3=		Term::ReadLine::Gnu.3

.include <bsd.port.post.mk>
