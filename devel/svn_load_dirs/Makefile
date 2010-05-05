# New ports collection makefile for:	svn_load_dirs
# Date created:		9 April 2007
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$

PORTNAME=	svn_load_dirs
PORTVERSION=	1.6.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/downloads/
DISTNAME=	subversion-${DISTVERSION}
DIST_SUBDIR=	subversion

MAINTAINER=	knu@freebsd.org
COMMENT=	A Perl script to load directories into a Subversion repository

RUN_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion

USE_BZIP2=	yes
USE_PERL5=	5.8.0+

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/client-side/svn_load_dirs

do-build:
	${SED} -E \
		-e 's|^(#!)/usr/bin/perl[[:>:]]|\1${PERL}|g' \
		-e 's|@SVN_BINDIR@|${LOCALBASE}/bin|g' \
		${WRKSRC}/svn_load_dirs.pl.in > ${WRKSRC}/svn_load_dirs.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/svn_load_dirs.pl ${PREFIX}/bin/svn_load_dirs
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/svn_load_dirs_property_table.example ${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/svn_load_dirs.README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
