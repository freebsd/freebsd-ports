# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Text-Kakasi
PORTVERSION=	2.04
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	CPAN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kakasi library module for Perl5

LIB_DEPENDS=	kakasi.3:${PORTSDIR}/japanese/kakasi

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
