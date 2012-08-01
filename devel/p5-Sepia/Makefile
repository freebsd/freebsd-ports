# New ports collection makefile for:	p5-Sepia
# Date created:		2011-12-01
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sepia
PORTVERSION=	0.992
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Simple Emacs-Perl Interface

BUILD_DEPENDS=	p5-Devel-Size>=0:${PORTSDIR}/devel/p5-Devel-Size \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Devel-LexAlias>=0:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Module-Info>=0:${PORTSDIR}/devel/p5-Module-Info \
		p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_EMACS=	yes
USE_GMAKE=	yes

MAN3=	Sepia.3 Sepia::Xref.3
MAN1=	sepl.1
INFO=	sepia

CONFIGURE_ARGS+=	--emacs ${EMACS_CMD} --lisp ${PREFIX}/${EMACS_SITE_LISPDIR}/sepia --info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
