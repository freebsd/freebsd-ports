# New ports collection makefile for:	p5-PCSC-Card
# Date created:		12 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	PCSC-Card
PORTVERSION=	1.4.9
CATEGORIES=	devel perl5
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	pcsc-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings for the PC/SC Lite Framework

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

PERL_CONFIGURE=	yes
MAKE_ENV=	"LOCALBASE=$(LOCALBASE)"

MAN3=		Chipcard::PCSC::Card.3 Chipcard::PCSC.3

post-patch:
	${REINPLACE_CMD} -e "s,-I/usr/local/pcsc/include,${LOCALBASE}/include/PCSC," \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
