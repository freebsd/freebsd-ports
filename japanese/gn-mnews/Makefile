# New ports collection makefile for:	gn-mnews
# Date created:			7 Feb 1997
# Whom:				Kiroh HARADA <kiroh@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gn-mnews
PORTVERSION=	1.20
CATEGORIES=	japanese news
MASTER_SITES=	ftp://ftp.mei.co.jp/free/Network/news/readers/
DISTNAME=	mnews${PORTVERSION:S/.//}

MAINTAINER=	seiken@ARGV.AC

RUN_DEPENDS=	gninews:${PORTSDIR}/japanese/gn-gnspool \
		mnews:${PORTSDIR}/japanese/mnews

NO_PACKAGE=	"Redistribution of binary built from modified source is prohibited"
BROKEN=		"Couldn't fetch now"

WRKSRC=		${WRKDIR}/mnews-${PORTVERSION}/build

do-configure:
	@for f in Makefile site_dep.h ; do \
	  ${SED} s+@PREFIX@+${PREFIX}+ ${FILESDIR}/$$f.in > ${WRKSRC}/$$f ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mnews ${PREFIX}/bin/gnmnews

post-install:
	@${ECHO} "You must have gn/gnspool configured to your environment,"
	@${ECHO} "before using gn-mnews.  Please refer to gn documents and"
	@${ECHO} "${PREFIX}/share/doc/mnews/gnspool.doc"

.include <bsd.port.mk>
