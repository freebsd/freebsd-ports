# ex:ts=8
# Ports collection makefile for:	ipa
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	IPA
PORTVERSION=	1.02
CATEGORIES=	graphics
MASTER_SITES=	http://www.prima.eu.org/IPA/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Processing Algorithms

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Prima.pm:${PORTSDIR}/x11-toolkits/p5-Prima
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		iterm.1
MAN3=		IPA.3
MANCOMPRESSED=	yes

do-configure:
	@(cd ${WRKSRC} ; ${PERL} ./${CONFIGURE_SCRIPT})
	@(cd ${WRKSRC} ; ${REINPLACE_CMD} -e 's,-o,-fPIC &, ; s|perl/man|man|' Makefile)

.include <bsd.port.mk>
