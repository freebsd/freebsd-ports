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
COMMENT=	A Perl script to load directories into a Subversion repository

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion

USES=		perl5

PLIST_FILES=	bin/svn_load_dirs

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif
.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

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
	${INSTALL_SCRIPT} ${WRKSRC}/svn_load_dirs.pl ${PREFIX}/bin/svn_load_dirs
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/svn_load_dirs_property_table.example ${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	for f in LICENSE_AFL3.txt svn_load_dirs.README; do \
		${INSTALL_DATA} ${WRKSRC}/"$$f" ${DOCSDIR}/; \
	done
.endif

.include <bsd.port.post.mk>
