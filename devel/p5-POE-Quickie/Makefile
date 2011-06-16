# New ports collection makefile for:	p5-POE-Quickie
# Date created:		2011-05-04
# Whom:			Takefu
#
# $FreeBSD$
#

PORTNAME=	POE-Quickie
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	takefu@airport.fm
COMMENT=	A lazy way to wrap blocking code and programs

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE

LICENSE=	GPLv1 ART10
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS=	Capture "Enable p5-Capture-Tiny support" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_Capture)
BUILD_DEPENDS+=	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny
.endif

PERL_CONFIGURE=	yes

MAN3=		POE::Quickie.3

post-patch:
.if !defined(WITH_Capture)
	${REINPLACE_CMD} -e "s,^.*Capture::Tiny.*,," ${BUILD_WRKSRC}/Makefile.PL
.endif
	${RM} ${WRKSRC}/lib/POE/Quickie.pm.orig

.include <bsd.port.mk>
