# New ports collection makefile for:	polygraph
# Version required:	1.2.0
# Date created:         3 March 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	polygraph-1.2.0-src
PKGNAME=	polygraph-1.2.0
CATEGORIES=	benchmarks www
MASTER_SITES=	http://polygraph.ircache.net/sources/	\
		http://www.chg.ru/~dima/

MAINTAINER=	dima@Chg.RU

WRKSRC=		${WRKDIR}/polygraph/src

post-patch:
		@ ${MV} ${WRKSRC}/exprep.pl ${WRKSRC}/exprep.pl.pre_sed
		@ ${SED} -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/exprep.pl.pre_sed > ${WRKSRC}/exprep.pl
		@ ${MV} ${WRKSRC}/../tools/BB/bb.pl ${WRKSRC}/../tools/BB/bb.pl.pre_sed1
		@ ${SED} -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/../tools/BB/bb.pl.pre_sed1> ${WRKSRC}/../tools/BB/bb.pl.pre_sed
		@ ${SED} -e 's#/usr/people/bakeoff/BB#${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph#' \
		${WRKSRC}/../tools/BB/bb.pl.pre_sed> ${WRKSRC}/../tools/BB/bb.pl

do-install:

		@ ${INSTALL_PROGRAM} ${WRKSRC}/polyclt ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/polysrv ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/lr ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/lx ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/exprep.pl ${PREFIX}/bin/exprep
		@ ${INSTALL_SCRIPT} ${WRKSRC}/../tools/BB/bb.pl ${PREFIX}/bin
		@ ${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph
.for file in	Blob.pm Executer.pm Tools.pm Command.pm Logger.pm
		@ ${INSTALL_SCRIPT} ${WRKSRC}/../tools/BB/$(file) \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/polygraph
.endfor

.include <bsd.port.mk>
