# New ports collection makefile for:	p5-XML-WBXML
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-WBXML
PORTVERSION=	0.03
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert between XML and WBXML using libwbxml2

LIB_DEPENDS=	wbxml2:${PORTSDIR}/textproc/wbxml2

MAN3=	XML::WBXML.3

PERL_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-I.,-I. -I${LOCALBASE}/include,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
