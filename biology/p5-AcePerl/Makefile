# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	AcePerl
PORTVERSION=	1.92
PORTREVISION=	2
CATEGORIES=	biology databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Ace
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 interface to the ACEDB genome database system

RUN_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAKE_JOBS_UNSAFE=  yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@ ${SED} -e 's|XX__CC__XX|${CC}|' < ${FILESDIR}/FREEBSD_DEF \
	  > ${WRKSRC}/acelib/wmake/FREEBSD_DEF

.include <bsd.port.post.mk>
