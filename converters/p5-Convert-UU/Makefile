# New ports collection makefile for:	p5-Convert-UU
# Version required:			0.20
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.15 1998/09/15 21:31:30 asami Exp $
#

DISTNAME=	Convert-UU-0.20
PKGNAME=	p5-Convert-UU-0.20
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         perl paths
.endif

MAN1=		puuencode.1 puudecode.1
MAN3=		Convert::UU.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
