# Created by: tabthorpe
# $FreeBSD$

PORTNAME=	Locale-PO
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Perl module for manipulating .po entries from GNU gettext

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

.include <bsd.port.mk>
