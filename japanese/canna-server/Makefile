# Created by: hrs
# $FreeBSD$

PORTNAME=	canna
PORTVERSION=	3.7p3
PORTREVISION=	10
CATEGORIES=	japanese
MASTER_SITES=	OSDN/canna
PKGNAMESUFFIX=	-server
DISTNAME=	Canna${PORTVERSION:S/.//g}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kana-to-Kanji conversion system, binary part

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcanna.so:japanese/canna-lib

USES=		imake tar:bzip2
USE_RC_SUBR=	canna
INSTALL_TARGET=	instserver instclient
PORTDOCS=	canna.bib canna.sty Imakefile README.jp Makefile \
		intern lisp man
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	    ${MAKEFILE} ${MAKE_ARGS} install.man
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${CP} -R ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
