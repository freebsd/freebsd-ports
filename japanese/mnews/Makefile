# New ports collection makefile for:	mnews
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mnews
PORTVERSION=	1.22
CATEGORIES=	japanese news ipv6
MASTER_SITES=	ftp://ftp.leo.chubu.ac.jp/pub/network/mnews/
DISTNAME=	mnews${PORTVERSION:S/.//}

MAINTAINER=	seiken@ARGV.AC

WRKSRC=		${WRKDIR}/mnews-${PORTVERSION}/build
MAN1=		mnews.1
MANLANG=	ja

DOCS=		FAQ.doc IPv6.doc IPv6_en.doc board.doc gnspool.doc mnews.doc \
		prerel.doc present.doc read1ST.doc readme.doc update.doc \
		year2000.doc youbin.doc
SAMPLES=	_mnews.smp jnames.fj jnames.jp jnames.smp jnames.tnn

GNSPOOL?=	0
IMPUT?=		0

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
MAKE_ENV+=	USE_INET6=yes
.endif

do-configure:
.for f in Makefile site_dep.h
	${SED} -e s+@PREFIX@+${PREFIX}+ \
		-e s+@GNSPOOL@+${GNSPOOL}+ \
		-e s+@IMPUT@+${IMPUT}+ \
		${FILESDIR}/${f}.in > ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mnews ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/mnews
	${INSTALL_DATA} ${WRKSRC}/../etc/jnames.fj ${PREFIX}/etc/mnews/jnames.default
.if !exists(${PREFIX}/etc/mnews/jnames)
	${INSTALL_DATA} ${WRKSRC}/../etc/jnames.fj ${PREFIX}/etc/mnews/jnames
.endif
	${MKDIR} ${PREFIX}/share/examples/mnews
.for f in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/../etc/${f} ${PREFIX}/share/examples/mnews
.endfor
	${INSTALL_MAN} ${WRKSRC}/../doc/mnews.1 ${PREFIX}/man/ja/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mnews
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../doc/${f} ${PREFIX}/share/doc/mnews
.endfor
.endif

post-install:
	@${ECHO} my.domain.com > ${PREFIX}/etc/mnews/default-domain.default
	@if [ \! -e ${PREFIX}/etc/mnews/default-domain ]; then \
	if [ X${BATCH} = X ]; then \
		while [ X$$domain = X ]; do \
			read -p "Enter the domain name of this host>" domain; \
		done; \
		${ECHO} $$domain > ${PREFIX}/etc/mnews/default-domain; \
	else \
		${ECHO} "Now, you need to make sure ${PREFIX}/etc/mnews/default-domain"; \
		${ECHO} "contains correct domain name."; \
		${CP} ${PREFIX}/etc/mnews/default-domain.default ${PREFIX}/etc/mnews/default-domain; \
	fi \
	fi
	@${ECHO} "Please refer to the files in:"
	@${ECHO} "${PREFIX}/share/doc/mnews & ${PREFIX}/share/examples/mnews."

.include <bsd.port.post.mk>
