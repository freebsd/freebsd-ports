# New ports collection makefile for:	p5-GD-TextUtil
# Version required:			0.70
# Date created:				21 February 2000
# Whom:	      				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=	GDTextUtil-0.70
PKGNAME=	p5-GD-TextUtil-0.70
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD

MAINTAINER=	dima@Chg.RU

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD::Text.3 GD::Text::Wrap.3 GD::Text::Align.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
