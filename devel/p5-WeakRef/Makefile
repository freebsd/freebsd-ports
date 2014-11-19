# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	WeakRef
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LUKKA
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	API to the Perl weak references

USES=		perl5
USE_PERL5=	configure

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/WeakRef/WeakRef.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/WeakRef/WeakRef.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/WeakRef/WeakRef.so

.include <bsd.port.mk>
