# New ports collection makefile for:	cil
# Date created:        11 October 2003
# Whom:                Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cil
PORTVERSION=	1.3.7
CATEGORIES=	devel lang
MASTER_SITES=	SF \
		http://hal.cs.berkeley.edu/cil/distrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlopt:${PORTSDIR}/lang/ocaml

CONFLICTS=	ccured-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BINFILES=	cilly patcher teetwo
LIBFILES=	Cilly.pm KeptFile.pm OutputFile.pm TempFile.pm

post-patch:
	@${REINPLACE_CMD} -e 's:@CILHOME@/lib:${SITE_PERL}/CIL:g; s:\@CILHOME\@:${PREFIX}:g' ${WRKSRC}/bin/CilConfig.pm.in
	@${REINPLACE_CMD} -e 's|$$::cilhome|${PREFIX}|g; s|obj/$$::archos|libexec/cil|g' ${WRKSRC}/bin/cilly
	@${REINPLACE_CMD} -e 's|^use Cilly;|use CIL::Cilly|' ${WRKSRC}/bin/cilly
	@${REINPLACE_CMD} -e 's|^use KeptFile;|use CIL::KeptFile;|; s|^use OutputFile;|use CIL::OutputFile;|; s|^use TempFile;|use CIL::TempFile;|' ${WRKSRC}/lib/Cilly.pm.in
	@${REINPLACE_CMD} -e 's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/lib/KeptFile.pm
	@${REINPLACE_CMD} -e 's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/lib/TempFile.pm

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DOCSDIR}
.endif
.for f in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin/
.endfor
	${MKDIR} ${SITE_PERL}/CIL
.for f in ${LIBFILES}
	 ${INSTALL_DATA} ${WRKSRC}/lib/${f} ${SITE_PERL}/CIL/
.endfor
	${INSTALL_DATA} ${WRKSRC}/bin/CilConfig.pm ${SITE_PERL}/
	${MKDIR} ${PREFIX}/libexec/cil

.include <bsd.port.mk>
