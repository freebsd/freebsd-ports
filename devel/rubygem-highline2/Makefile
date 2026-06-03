PORTNAME=	highline
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-level IO library for command-line interfaces
WWW=		https://github.com/JEG2/highline

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 3.4
RUN_DEPENDS+=	rubygem-abbrev>=0:textproc/rubygem-abbrev
.endif

.include <bsd.port.post.mk>
