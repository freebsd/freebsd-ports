# New ports collection makefile for:	p5-Pg
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pg
POSTVERSION=	7.2
CATEGORIES=	databases perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	girgen@partitur.se

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

USE_PERL5=	yes

CONFIGURE_ARGS=	--with-perl

MAN3=		Pg.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAKE_ARGS+=	-C src/interfaces/perl5
MAKEFILE=	GNUmakefile

post-patch:
	cd ${WRKSRC}/src/interfaces/perl5 ;\
	cp GNUmakefile GNUmakefile.old ;\
	${SED} -e 's,\$$\$$abs_libpq_builddir,${LOCALBASE}/lib,; \
		   s,Makefile\ libpq-all,Makefile,' \
		 < GNUmakefile.old > GNUmakefile

.include <bsd.port.mk>
