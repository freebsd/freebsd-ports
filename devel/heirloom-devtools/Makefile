PORTNAME=	heirloom-devtools
PORTVERSION=	070527
CATEGORIES=	devel
MASTER_SITES=	SF/heirloom/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OpenSolaris yacc, lex, m4, make, and SCCS
WWW=		https://heirloom.sourceforge.net/devtools.html

LICENSE=	CDDL

USES=		tar:bzip2

ALL_TARGET=	#empty
MAKE_ARGS+=	INSTALL="${INSTALL}" \
		BINDIR=${BINDIR} \
		SUSBIN=${SUSBIN} \
		LIBDIR=${LIBDIR} \
		HDRSDIR=${HDRSDIR} \
		MANDIR=${MANDIR} \
		ROOT=${STAGEDIR}
MAKEFILE=	makefile
CFLAGS+=	-fcommon
SUB_FILES=	${PORTNAME}.conf
PLIST_SUB=	LIBEXECDIR=heirloom/libexec

MANPREFIX=	${PREFIX}/heirloom/share
DATADIR=	${PREFIX}/heirloom/share

BINDIR?=	${PREFIX}/heirloom/bin
SUSBIN?=	${PREFIX}/heirloom/bin/posix
LIBDIR?=	${PREFIX}/heirloom/libexec
HDRSDIR?=	${DATADIR}/lib/make
MANDIR?=	${MANPREFIX}/man

PORTDOCS=	 *

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/man.d

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
