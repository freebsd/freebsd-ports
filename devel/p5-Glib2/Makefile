# New ports collection makefile for:	p5-Glib2
# Date created:				26 Oct 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Glib2
PORTVERSION=	1.240
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Glib SF/gtk2-perl/Glib/${PORTVERSION}
PKGNAMEPREFIX=	p5-
DISTNAME=	Glib-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	This module provides access to Glib and GObject libraries

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends

USE_GNOME=	glib20
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/2//}-${PORTVERSION}

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
