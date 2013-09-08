# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deputy
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://deputy.cs.berkeley.edu/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Advanced C compiler that enforces type and memory safety

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlopt:${PORTSDIR}/lang/ocaml

CONFLICTS=	cil-*

ONLY_FOR_ARCHS=	i386 amd64
USES=		perl5
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		deputy.1

INCFILES=	annots.h checks.h
LIBFILES=	Cilly.pm KeptFile.pm OutputFile.pm TempFile.pm
EXECFILES=	deputy.asm.exe deputy.byte.exe deputy_libc.o

post-patch:
	@${REINPLACE_CMD} -e 's:@CILHOME@/lib:${SITE_PERL}/CIL:g; s:\@CILHOME\@:${PREFIX}:g' ${WRKSRC}/cil/bin/CilConfig.pm.in
	@${REINPLACE_CMD} -e 's|^use KeptFile;|use CIL::KeptFile;|; s|^use OutputFile;|use CIL::OutputFile;|; s|^use TempFile;|use CIL::TempFile;|' ${WRKSRC}/cil/lib/Cilly.pm
	@${REINPLACE_CMD} -e 's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/cil/lib/KeptFile.pm
	@${REINPLACE_CMD} -e 's|^use OutputFile;|use CIL::OutputFile;|' ${WRKSRC}/cil/lib/TempFile.pm
	@${REINPLACE_CMD} -e 's|^use Cilly;|use CIL::Cilly;|' ${WRKSRC}/lib/Deputy.pm
	@${REINPLACE_CMD} -e 's|$$::deputyhome|${PREFIX}|g; s|obj/$$::archos|libexec/deputy|g' ${WRKSRC}/lib/Deputy.pm
#	@${REINPLACE_CMD} -e '/ NATIVECAML=1/s/^/#gmake-3.82 BUG/' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/deputy ${PREFIX}/bin/
	${MKDIR} ${SITE_PERL}/CIL
.for f in ${LIBFILES}
	 ${INSTALL_DATA} ${WRKSRC}/cil/lib/${f} ${SITE_PERL}/CIL/
.endfor
	${INSTALL_DATA} ${WRKSRC}/cil/bin/CilConfig.pm ${SITE_PERL}/
	${INSTALL_DATA} ${WRKSRC}/lib/Deputy.pm ${SITE_PERL}/
	${MKDIR} ${PREFIX}/libexec/deputy
.for f in ${EXECFILES}
	${INSTALL} ${WRKSRC}/obj/${ARCH}_FREEBSD/${f} ${PREFIX}/libexec/deputy/
.endfor
	${MKDIR} ${PREFIX}/include/deputy
	${INSTALL_DATA} ${WRKSRC}/include/libc_patch.i ${PREFIX}/include/deputy/
.for f in ${INCFILES}
	${INSTALL_DATA} ${WRKSRC}/include/deputy/${f} ${PREFIX}/include/deputy/
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/deputy.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
