# New ports collection makefile for:	rrdtool
# Version required:			1.0.7
# Date created:				20 July 1999
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=	rrdtool-1.0.7
CATEGORIES=	net
MASTER_SITES=	http://ee-staff.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	dima@Chg.RU

USE_PERL5=	YES
MAKE_ENV+=	PERL=${PERL}

GNU_CONFIGURE=	YES

CONFIGURE_ENV=	PERL=${PERL}

MAN1=		RRDp.1 RRDs.1 bin_dec_hex.1 rrdcgi.1 rrdcreate.1 rrddump.1 \
		rrdfetch.1 rrdgraph.1 rrdlast.1 rrdresize.1 rrdrestore.1 \
		rrdtool.1 rrdtune.1 rrdtutorial.1 rrdupdate.1
MAN3=		RRDp.3 RRDs.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/rrdtool ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/src/rrdcgi ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/contrib/log2rrd/log2rrd.pl ${PREFIX}/bin
		${MKDIR} -m 755 ${PREFIX}/share/examples/rrdtool
		${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${PREFIX}/share/examples/rrdtool
		${INSTALL_SCRIPT} ${WRKSRC}/examples/*.cgi ${PREFIX}/share/examples/rrdtool
		${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
		${MKDIR} -m 755 ${PREFIX}/share/doc/rrdtool
		${INSTALL_DATA} ${WRKSRC}/contrib/log2rrd/README ${PREFIX}/share/doc/rrdtool/README.log2rrd
		${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/rrdtool
.endif
		for dir in piped shared; do \
			cd ${WRKSRC}/perl-$$dir; ${MAKE} install; \
		done

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
