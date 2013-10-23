# Created by: Alexander Leidinger <netchild@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cil
PORTVERSION=	1.7.3
CATEGORIES=	devel lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

CONFLICTS=	ccured-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USES=		gmake perl5
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*
PLIST_FILES=	${BINFILES:S,^,bin/,} \
		%%SITE_PERL%%/CilConfig.pm \
		${LIBFILES:S,^,%%SITE_PERL%%/CIL/,} \
		${LIBBINS:S,^,%%SITE_PERL%%/CIL/,} \
		${LIBAFILES:S,^,%%SITE_PERL%%/CIL/,}
PLIST_DIRS=	%%SITE_PERL%%/CIL/App/Cilly \
		%%SITE_PERL%%/CIL/App \
		%%SITE_PERL%%/CIL
BINFILES=	cilly cilly.native
LIBAFILES=	App/Cilly.pm
LIBFILES=	App/Cilly/KeptFile.pm \
		App/Cilly/OutputFile.pm \
		App/Cilly/TempFile.pm
LIBBINS=	patcher

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'35 s|make|gmake|g' ${WRKSRC}/myocamlbuild.ml
	@${REINPLACE_CMD} -e \
		's|@CILHOME@/lib|${SITE_PERL}/CIL|g ; \
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

do-install:
.for f in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${SITE_PERL}
	${INSTALL_DATA} ${WRKSRC}/lib/App/Cilly/CilConfig.pm ${SITE_PERL}
	@${MKDIR} ${SITE_PERL}/CIL/App/Cilly
.for f in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${SITE_PERL}/CIL/App/Cilly
.endfor
.for f in ${LIBAFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${SITE_PERL}/CIL/App
.endfor
.for f in ${LIBBINS}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${SITE_PERL}/CIL
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
