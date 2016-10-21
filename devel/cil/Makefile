# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cil
PORTVERSION=	1.7.3
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	ccured-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USES=		gmake perl5
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
OCAML_PKGDIRS=
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*
PLIST_FILES=	${BINFILES:S,^,bin/,} \
		%%SITE_PERL%%/CilConfig.pm \
		${LIBFILES:S,^,%%SITE_PERL%%/CIL/,} \
		${LIBBINS:S,^,%%SITE_PERL%%/CIL/,} \
		${LIBAFILES:S,^,%%SITE_PERL%%/CIL/,}
BINFILES=	cilly cilly.native
LIBAFILES=	App/Cilly.pm
LIBFILES=	App/Cilly/KeptFile.pm \
		App/Cilly/OutputFile.pm \
		App/Cilly/TempFile.pm
LIBBINS=	patcher

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'35 s|make|gmake|g' ${WRKSRC}/myocamlbuild.ml
	@${REINPLACE_CMD} -e \
		's|@CILHOME@/lib|${PREFIX}/${SITE_PERL_REL}/CIL|g ; \
		s|\@CILHOME\@|${PREFIX}|g' \
		${WRKSRC}/lib/App/Cilly/CilConfig.pm.in
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|${PERL}|' ${WRKSRC}/lib/patcher
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|${PERL}| ; \
		 s|$$::cilhome|${PREFIX}|g ; \
		 s|obj/$$::archos|libexec/cil|g ; \
		 s|^use Cilly;|use CIL::Cilly|' ${WRKSRC}/bin/cilly
	@${REINPLACE_CMD} -e \
		's|^use KeptFile;|use CIL::KeptFile;| ; \
		 s|^use OutputFile;|use CIL::OutputFile;| ; \
		 s|^use TempFile;|use CIL::TempFile;|' \
			${WRKSRC}/lib/App/Cilly.pm.in
	@${REINPLACE_CMD} -e \
		's|^use OutputFile;|use CIL::OutputFile;|' \
		${WRKSRC}/lib/App/Cilly/KeptFile.pm
	@${REINPLACE_CMD} -e \
		's|^use OutputFile;|use CIL::OutputFile;|' \
		${WRKSRC}/lib/App/Cilly/TempFile.pm
	@${REINPLACE_CMD} '/MACHDEPCC/ s|gcc|${CC}|' ${WRKSRC}/Makefile.in

pre-install:
	@${STRIP_CMD} ${WRKSRC}/bin/cilly.native

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${BINFILES} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CIL/App/Cilly
	${INSTALL_DATA} ${WRKSRC}/lib/App/Cilly/CilConfig.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} ${LIBFILES} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CIL/App/Cilly)
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} ${LIBAFILES} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CIL/App)
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} ${LIBBINS} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/CIL)
# Remove orphan dir created by bsd.ocaml.mk
	-@${RMDIR} -p ${STAGEDIR}${OCAMLFIND_DESTDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${RM} -r ${WRKSRC}/doc/cilcode.tmp
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
