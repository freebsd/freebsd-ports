# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.144
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Glib SF/gtk2-perl
PKGNAMEPREFIX=	p5-
DISTNAME=	Glib-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/2//}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${TARGETDIR}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
