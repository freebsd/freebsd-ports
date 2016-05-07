# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	svn_load_dirs
PORTVERSION=	1.8.4
CATEGORIES=	devel
MASTER_SITES=	http://svn.apache.org/repos/asf/subversion/tags/${PORTVERSION}/contrib/client-side/svn_load_dirs/
DISTFILES=	LICENSE_AFL3.txt \
		svn_load_dirs.README \
		svn_load_dirs.pl.in \
		svn_load_dirs_property_table.example
DIST_SUBDIR=	subversion/${PORTNAME}-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Perl script to load directories into a Subversion repository

OPTIONS_DEFINE=	DOCS EXAMPLES

RUN_DEPENDS=	p5-URI>=0:net/p5-URI \
		${LOCALBASE}/bin/svn:devel/subversion

USES=		perl5

PLIST_FILES=	bin/svn_load_dirs

PORTEXAMPLES=	*
PORTDOCS=	*

do-extract:
	${MKDIR} ${WRKSRC}
	for f in ${DISTDIR}/${DIST_SUBDIR}/*; do \
		${CP} "$$f" ${WRKSRC}/; \
	done

do-build:
	${SED} -E \
		-e 's|^(#!)/usr/bin/perl[[:>:]]|\1${PERL}|g' \
		-e 's|@SVN_BINDIR@|${LOCALBASE}/bin|g' \
		${WRKSRC}/svn_load_dirs.pl.in > ${WRKSRC}/svn_load_dirs.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/svn_load_dirs.pl ${STAGEDIR}${PREFIX}/bin/svn_load_dirs
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/svn_load_dirs_property_table.example ${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in LICENSE_AFL3.txt svn_load_dirs.README; do \
		${INSTALL_DATA} ${WRKSRC}/"$$f" ${STAGEDIR}${DOCSDIR}/; \
	done

.include <bsd.port.mk>
