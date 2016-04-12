# Created by: ache
# $FreeBSD$

PORTNAME=	rar
PORTVERSION=	5.3.0
PORTEPOCH=	3
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	rarbsd-${PORTVERSION}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	File archiver (binary port)

LICENSE=	RAR
LICENSE_NAME=	RAR license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RESTRICTED=	only unmodified original package can be distributed
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar
PLIST_FILES=	bin/rar lib/default.sfx etc/rarfiles.lst man/cat1/rar.1.gz
PORTDOCS=	license.txt whatsnew.txt order.htm readme.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=	fails to install on ia64/powerpc/sparc64: File format not recognized
.elif ${ARCH} == "amd64" || ${ARCH} == "ia64"
.if !defined(HAVE_COMPAT_IA32_KERN)
HAVE_COMPAT_IA32_KERN!=	if ${SYSCTL} -n compat.ia32.maxvmem >/dev/null 2>&1; then ${ECHO_CMD} YES; fi
.endif
.if !defined(HAVE_COMPAT_IA32_KERN)
IGNORE=	requires a kernel with compiled-in IA32 compatibility
.endif
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000054
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:misc/compat9x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${STAGEDIR}${PREFIX}/bin/rar
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${STAGEDIR}${PREFIX}/man/cat1/rar.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${STAGEDIR}${PREFIX}/lib

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
