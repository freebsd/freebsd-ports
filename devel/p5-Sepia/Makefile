# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sepia
PORTVERSION=	0.992
PORTREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Simple Emacs-Perl Interface

BUILD_DEPENDS=	p5-Devel-Size>=0:devel/p5-Devel-Size \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Devel-LexAlias>=0:devel/p5-Devel-LexAlias \
		p5-libwww>=0:www/p5-libwww \
		p5-Module-Info>=0:devel/p5-Module-Info \
		p5-BSD-Resource>=0:devel/p5-BSD-Resource
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake makeinfo perl5
USE_PERL5=	configure
USE_EMACS=	yes

INFO=	sepia

CONFIGURE_ARGS+=	--emacs ${EMACS_CMD} --lisp ${PREFIX}/${EMACS_SITE_LISPDIR}/sepia --info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
