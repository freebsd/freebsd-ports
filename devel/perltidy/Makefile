# ex:ts=8
# New ports collection makefile for:	perltidy
# Date created:			Mar 4, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perltidy
PORTVERSION=	20020922
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Perl-Tidy-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Indents and reformats Perl scripts to make them easier to read

PERL_CONFIGURE=	yes

MAN1=		perltidy.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Perl::Tidy.3

.include <bsd.port.mk>
