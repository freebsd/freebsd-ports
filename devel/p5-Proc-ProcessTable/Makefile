# New ports collection makefile for:    Proc-ProcessTable
# Date created:                         Tue Jun 26 12:46:19 EDT 2001
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Proc-ProcessTable
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Proc
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the unix process table

PERL_CONFIGURE=	YES

MAN3=		Proc::ProcessTable::Process.3 \
		Proc::Killall.3 \
		Proc::ProcessTable.3 \
		Proc::Killfam.3
PORTDOCS=	README README.freebsd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
