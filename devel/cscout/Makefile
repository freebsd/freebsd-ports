# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	cscout
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.spinellis.gr/cscout/ \
		http://www.dmst.aueb.gr/dds/cscout/
DISTFILES=	${DISTNAME}-neutral${EXTRACT_SUFX} \
		${DISTNAME}-fbsd-${ARCH}${EXTRACT_SUFX}

MAINTAINER=	dds@FreeBSD.org
COMMENT=	Source code analyzer and refactoring browser for C program collections

LIB_DEPENDS+=	libc.so.6:misc/compat6x

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	The port fetches and installs precompiled binaries
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/csmake bin/cswc

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
.if exists(/usr/include/g++/)
	${REINPLACE_CMD} -i "" -e 's:g++-3:g++:g' \
	    ${WRKSRC}/etc/cscout_incs.FBSD_GCC
.endif
	(${SED} -n '1,/Platform defines begin/p' \
	    ${WRKSRC}/etc/cscout_defs.FBSD_GCC && \
		${CPP} -O -dM /dev/null | ${SORT} && \
		${SED} -n '/Platform defines end/,$$p' \
		    ${WRKSRC}/etc/cscout_defs.FBSD_GCC ) \
		    > ${WRKDIR}/cscout_defs.h
	${CP} ${WRKDIR}/cscout_defs.h ${WRKSRC}/etc/cscout_defs.FBSD_GCC

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cscout ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cswc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/csmake ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/etc/cscout_incs.FBSD_GCC ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/etc/cscout_defs.FBSD_GCC ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/man/cscout.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/cswc.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
