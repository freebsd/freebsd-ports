# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Memcached-libmemcached
PORTVERSION=	1.001801
CATEGORIES=	databases devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Thin fast full interface to the libmemcached client API

LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes

post-extract:
	@${RM} -r ${WRKDIR}/src

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.if ${OSVERSION} > 1000000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.PL-10
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.PL-9
.endif
.endif

.include <bsd.port.post.mk>
