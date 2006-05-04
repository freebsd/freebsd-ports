# New ports collection makefile for:	p5-PCSC-Card
# Date created:		12 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	PCSC-Card
PORTVERSION=	1.4.2
CATEGORIES=	devel perl5
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	pcsc-perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl bindings for the PC/SC Lite Framework

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Requires perl-5.6.0 or better to build correctly
.endif

PERL_CONFIGURE=	yes
MAKE_ENV=	"LOCALBASE=$(LOCALBASE)"

MAN3=		Chipcard::PCSC::Card.3 Chipcard::PCSC.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${REINPLACE_CMD} -e "s,-I/usr/local/pcsc/include,${LOCALBASE}/include/PCSC," \
		${WRKSRC}/Makefile.PL


.include <bsd.port.post.mk>
