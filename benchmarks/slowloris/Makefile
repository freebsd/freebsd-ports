# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	slowloris
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low-bandwidth, yet greedy and poisonous HTTP client

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

NO_ARCH=	yes
NO_BUILD=	yes

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	slowloris.pl

PLIST_FILES=	bin/slowloris

PERL_THREADS?=	yes

.if ${PERL_THREADS} != "yes"
EXTRA_PATCHES+=	${FILESDIR}/extra-nothreads
.else
RUN_DEPENDS+=	p5-threads-shared>=0:devel/p5-threads-shared
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slowloris.pl \
		${STAGEDIR}/${PREFIX}/bin/slowloris

.include <bsd.port.mk>
