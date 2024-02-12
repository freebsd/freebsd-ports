PORTNAME=	svn_load_dirs
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://svn.apache.org/repos/asf/subversion/tags/${PORTVERSION}/contrib/client-side/svn_load_dirs/
DISTFILES=	LICENSE_AFL3.txt \
		svn_load_dirs.README \
		svn_load_dirs.pl.in \
		svn_load_dirs_property_table.example
DIST_SUBDIR=	subversion/${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl script to load directories into a Subversion repository
WWW=		https://svn.apache.org/repos/asf/subversion/branches/scons-build-system/www/tools_contrib.html #svn_load_dirs_pl

OPTIONS_DEFINE=	DOCS EXAMPLES

RUN_DEPENDS=	p5-URI>=0:net/p5-URI
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	svn:devel/subversion-lts
.else
RUN_DEPENDS+=	svn:devel/subversion
.endif

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
