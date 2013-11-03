# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Search-Xapian10
PORTVERSION=	1.0.23.0
CATEGORIES=	databases perl5
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION:R}/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	xapian-core10>=1.0.22:${PORTSDIR}/databases/xapian-core10
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-Search-Xapian-1.[^0]*

USES=		perl5
USE_PERL5=	configure
CC=		${CXX}

post-patch:
	@${REINPLACE_CMD} -e 's/^if (defined $$builddir/if (0/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
