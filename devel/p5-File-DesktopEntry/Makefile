# New ports collection makefile for:	p5-File-DesktopEntry
# Date created:		2006-05-31
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	File-DesktopEntry
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/P/PA/PARDUS/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Object to handle desktop files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=	File::DesktopEntry.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
IGNORE=	newer perl version required. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
