# New ports collection makefile for:	cil
# Date created:        11 October 2003
# Whom:                Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cil
PORTVERSION=	1.5.1
CATEGORIES=	devel lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlopt:${PORTSDIR}/lang/ocaml

OPTIONS_DEFINE=	DOCS

CONFLICTS=	ccured-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*
PLIST_FILES=	${BINFILES:S,^,bin/,} ${LEXECFILES:S,^,libexec/cil/,} \
		%%SITE_PERL%%/CilConfig.pm ${LIBFILES:S,^,%%SITE_PERL%%/CIL/,}
PLIST_DIRS=	%%SITE_PERL%%/CIL libexec/cil

BINFILES=	cilly patcher teetwo
LIBFILES=	Cilly.pm KeptFile.pm OutputFile.pm TempFile.pm
LEXECFILES=	cilly.asm.exe cilly.byte.exe

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|@CILHOME@/lib|${SITE_PERL}/CIL|g ; \
		 s|\@CILHOME\@|${PREFIX}|g' ${WRKSRC}/bin/CilConfig.pm.in
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|${PERL}| ; \
		 s|$$::cilhome|${PREFIX}|g ; \
		 s|obj/$$::archos|libexec/cil|g ; \
		 s|^use Cilly;|use CIL::Cilly|' ${WRKSRC}/bin/cilly
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|${PERL}|' ${WRKSRC}/bin/patcher
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*|/bin/sh|' ${WRKSRC}/bin/teetwo
	@${REINPLACE_CMD} -e \
		's|^use KeptFile;|use CIL::KeptFile;| ; \
		 s|^use OutputFile;|use CIL::OutputFile;| ; \
		 s|^use TempFile;|use CIL::TempFile;|' ${WRKSRC}/lib/Cilly.pm.in
	@${REINPLACE_CMD} -e \
		's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/lib/KeptFile.pm
	@${REINPLACE_CMD} -e \
		's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/lib/TempFile.pm

do-install:
.for f in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${SITE_PERL}
	${INSTALL_DATA} ${WRKSRC}/bin/CilConfig.pm ${SITE_PERL}
	@${MKDIR} ${SITE_PERL}/CIL
.for f in ${LIBFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${SITE_PERL}/CIL
.endfor
	@${MKDIR} ${PREFIX}/libexec/cil
.for f in ${LEXECFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/obj/${ARCH}_${OPSYS:U}/${f} ${PREFIX}/libexec/cil
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
