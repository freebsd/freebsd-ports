# ex:ts=8
# Ports collection makefile for:	ipa
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	IPA
PORTVERSION=	1.00
CATEGORIES=	graphics
MASTER_SITES=	http://www.prima.eu.org/IPA/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Prima.pm:${PORTSDIR}/x11-toolkits/p5-Prima
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

do-configure:
	@(cd ${WRKSRC} ; ${PERL} ./${CONFIGURE_SCRIPT})

.include <bsd.port.mk>
