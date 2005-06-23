# New ports collection makefile for:	p5-Config-General
# Date created:				August 27 2002
# Whom:	      				Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-General
PORTVERSION=	2.29
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for handling Apache-style configuration files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Config::General::Extended.3 Config::General::Interpolated.3 \
		Config::General.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
post-patch:
	@${REINPLACE_CMD} -e 's|::Heavy||' ${WRKSRC}/General.pm
.endif

.include <bsd.port.post.mk>
