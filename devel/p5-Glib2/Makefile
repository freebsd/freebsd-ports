# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.080
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TS/TSCH/:cpan \
		gtk2-perl/:sf
PKGNAMEPREFIX=	p5-
DISTFILES=	Glib-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		Glib-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends

BROKEN=		Unfetchable

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	disable-threadsafe
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/2//}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
