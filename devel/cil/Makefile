# New ports collection makefile for:	cil
# Date created:        11 October 2003
# Whom:                Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cil
PORTVERSION=	1.2.3
CATEGORIES=	devel lang
MASTER_SITES=	http://manju.cs.berkeley.edu/cil/distrib/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Infrastructure for C Program Analysis and Transformation

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlopt:${PORTSDIR}/lang/ocaml

CONFLICTS=	ccured-*

ONLY_FOR_ARCHS=	i386
USE_PERL5=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

BINFILES=	cilly patcher teetwo
LIBFILES=	Cilly.pm KeptFile.pm OutputFile.pm TempFile.pm
EXECFILES=	cilly.byte.exe machdep.exe

post-patch:
	@${REINPLACE_CMD} -e 's:@CILHOME@/lib:${SITE_PERL}/CIL:g; s:\@CILHOME\@:${PREFIX}:g' ${WRKSRC}/bin/CilConfig.pm.in
	@${REINPLACE_CMD} -e 's|$$::cilhome|${PREFIX}|g; s|obj/$$::archos|libexec/cil|g' ${WRKSRC}/bin/cilly

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${DOCSDIR}
.endif
.for file in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${PREFIX}/bin/
.endfor
	${MKDIR} ${SITE_PERL}/CIL
.for file in ${LIBFILES}
	 ${INSTALL_DATA} ${WRKSRC}/lib/${file} ${SITE_PERL}/CIL/
.endfor
	${INSTALL_DATA} ${WRKSRC}/bin/CilConfig.pm ${SITE_PERL}/
	${MKDIR} ${PREFIX}/libexec/cil
.for file in ${EXECFILES}
	${INSTALL} ${WRKSRC}/obj/x86_LINUX/${file} ${PREFIX}/libexec/cil/
.endfor

.include <bsd.port.mk>
