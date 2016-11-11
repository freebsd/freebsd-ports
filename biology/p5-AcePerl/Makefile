# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	AcePerl
PORTVERSION=	1.92
PORTREVISION=	4
CATEGORIES=	biology databases perl5
MASTER_SITES=	CPAN/Ace
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the ACEDB genome database system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Cache>=0:devel/p5-Cache-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN_aarch64=	Fails to link: unresolvable R_AARCH64_ADR_PREL_PG_HI21 relocation

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${SED} -e 's|XX__CC__XX|${CC}|' < ${FILESDIR}/FREEBSD_DEF \
	  > ${WRKSRC}/acelib/wmake/FREEBSD_DEF

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Ace/Freesubs/Freesubs.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Ace/RPC/RPC.so

.include <bsd.port.post.mk>
