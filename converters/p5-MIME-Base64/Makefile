# New ports collection makefile for:    p5-MIME-Base64
# Version required:                     2.06
# Date created:                         June 21th 1997
# Whom:                                 ache@freebsd.org
#
# $Id: Makefile,v 1.8 1998/09/15 21:31:30 asami Exp $
#

DISTNAME=       MIME-Base64-2.09
PKGNAME=        p5-MIME-Base64-2.09
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     MIME

MAINTAINER=	ports@FreeBSD.ORG

USE_PERL5=	YES

MAN3=           MIME::Base64.3 \
		MIME::QuotedPrint.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
