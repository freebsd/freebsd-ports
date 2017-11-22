# $FreeBSD$

PORTNAME=	Pthread-GetThreadId
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	LOCAL/eugen \
		http://www.grosbein.net/freebsd/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Access to kernel level POSIX thread id

LICENSE=	ARTPERL10

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_ARCH%%/Pthread/GetThreadId.pm \
		%%SITE_ARCH%%/auto/Pthread/GetThreadId/GetThreadId.so \
		%%PERL5_MAN3%%/Pthread::GetThreadId.3.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Pthread/GetThreadId/GetThreadId.so

.include <bsd.port.mk>
