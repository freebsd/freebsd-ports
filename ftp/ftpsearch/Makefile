# New ports collection makefile for:	ftpsearch
# Date created:		07 Dec 1996
# Whom:			Tor.Egge@idi.ntnu.no
#
# $FreeBSD$
#

PORTNAME=	ftpsearch
PORTVERSION=	1.0
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftpsearch.ntnu.no/pub/ftpsearch/

PATCH_SITES=	ftp://ftpsearch.ntnu.no/pub/ftpsearch/
PATCHFILES=	ftpsearch-1.0.patch1 \
		ftpsearch-1.0.patch2 \
		ftpsearch-1.0.patch3 \
		ftpsearch-1.0.patch4 \
		ftpsearch-1.0.patch5 \
		ftpsearch-1.0.patch6 \
		ftpsearch-1.0.patch7 \
		ftpsearch-1.0.patch8

MAINTAINER=	Tor.Egge@idi.ntnu.no
COMMENT=	A system for indexing contents on ftp servers

NO_PACKAGE=	"Hostname compiled in"

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	FTPSEARCHROOT=${PREFIX}/ftpsearch

MANPREFIX=${PREFIX}/ftpsearch
MAN1=	ftpsearch.1
MAN5=	cnames.5 ftpcli_config.5 sites.5 sites.alias.5 sites.skip.5
MAN7=	datasets.7
MAN8=	astat.8 autoupdateconfig.pl.8 cardusage.8 checkenv.pl.8 chknavig.8 \
	chksites.pl.8 domainhelp.8 freq.8 ftpcli.8 \
	ftpsearchshell.8 gateway.8 genaliases.8 gendataset.8 genit.pl.8 \
	genmotd.pl.8 genspecter.8 genspecter2.8 listsite.8 load.8 \
	makesuffix.8 mergesites.8 nsslave.8 parsesite.8 removeoldparsed.pl.8 \
	search.8 sgateway.8 siteadmin.pl.8 sortsuffix.8

pre-install:
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} \{} \;

post-install:
	${LN} -sf ${PREFIX}/ftpsearch/bin/gateway ${PREFIX}/bin/ftpsearch

.include <bsd.port.mk>
