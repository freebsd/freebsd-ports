# New ports collection makefile for:	cil
# Date created:        11 October 2003
# Whom:                Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cil
PORTVERSION=	1.3.4
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://manju.cs.berkeley.edu/cil/distrib/
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlopt:${PORTSDIR}/lang/ocaml

CONFLICTS=	ccured-*

ONLY_FOR_ARCHS=	i386
USE_PERL5=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

BINFILES=	cilly patcher teetwo
LIBFILES=	Cilly.pm KeptFile.pm OutputFile.pm TempFile.pm
EXECFILES=	cilly.byte.exe machdep.exe

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		does not work with perl < 5.6.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:@CILHOME@/lib:${SITE_PERL}/CIL:g; s:\@CILHOME\@:${PREFIX}:g' ${WRKSRC}/bin/CilConfig.pm.in
	@${REINPLACE_CMD} -e 's|$$::cilhome|${PREFIX}|g; s|obj/$$::archos|libexec/cil|g' ${WRKSRC}/bin/cilly

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
.for f in ${EXECFILES}
	${INSTALL} ${WRKSRC}/obj/x86_LINUX/${f} ${PREFIX}/libexec/cil/
.endfor

.include <bsd.port.post.mk>
