# New ports collection makefile for:	polygraph
# Date created:         3 March 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	polygraph
PORTVERSION=	2.2.7
CATEGORIES=	benchmarks www
MASTER_SITES=	http://polygraph.ircache.net/sources/tars/ \
		http://www.chg.ru/~dima/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	demon@FreeBSD.org

WRKSRC=		${WRKDIR}/polygraph

GNU_CONFIGURE=	YES

post-patch:
		@ ${MV} ${WRKSRC}/src/exprep.pl ${WRKSRC}/src/exprep.pl.pre_sed
		@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' \
		${WRKSRC}/src/exprep.pl.pre_sed > ${WRKSRC}/src/exprep.pl
		@ ${MV} ${WRKSRC}/tools/BB/bb.pl ${WRKSRC}/tools/BB/bb.pl.pre_sed
		@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' \
			-e 's#/usr/people/bakeoff/BB#${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph#' \
		${WRKSRC}/tools/BB/bb.pl.pre_sed> ${WRKSRC}/tools/BB/bb.pl

do-install:

.for file in	polyclt polysrv lr lx distr_test pop_test rng_test aka piper polymon
		@ ${INSTALL_PROGRAM} ${WRKSRC}/src/$(file) ${PREFIX}/bin
.endfor
		@ ${INSTALL_PROGRAM} ${WRKSRC}/src/udp2tcpd ${PREFIX}/sbin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/src/exprep.pl ${PREFIX}/bin/exprep
		@ ${INSTALL_SCRIPT} ${WRKSRC}/tools/BB/bb.pl ${PREFIX}/bin
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph
.for file in	Blob.pm Executer.pm Tools.pm Command.pm Logger.pm
		@ ${INSTALL_SCRIPT} ${WRKSRC}/tools/BB/$(file) \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph
.endfor

.include <bsd.port.mk>
