# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-WBXML
PORTVERSION=	0.03
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert between XML and WBXML using libwbxml2

LIB_DEPENDS=	wbxml2:${PORTSDIR}/textproc/wbxml2

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's,-I.,-I. -I${LOCALBASE}/include,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
