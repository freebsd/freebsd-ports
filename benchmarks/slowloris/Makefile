# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	slowloris
PORTVERSION=	0.7
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	The low bandwidth, yet greedy and poisonous HTTP client

USES=		perl5
NO_BUILD=	yes

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long

PLIST_FILES=	bin/slowloris

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PERL_THREADS=	yes

.if exists(${PERL})
PERL_THREADS!=	${PERL} -V::usethreads
.if ${PERL_THREADS} == "'define';"
RUN_DEPENDS+=	p5-threads-shared>=0:${PORTSDIR}/devel/p5-threads-shared
PERL_THREADS=	yes
.else
PERL_THREADS=	no
.endif
.endif

.if ${PERL_THREADS} != "yes"
EXTRA_PATCHES+=	${FILESDIR}/extra-nothreads
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slowloris.pl ${PREFIX}/bin/slowloris

.include <bsd.port.post.mk>
