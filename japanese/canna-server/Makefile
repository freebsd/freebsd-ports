PORTNAME=	canna
PORTVERSION=	3.8
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/canna-input/canna/releases/download/release-${PORTVERSION}/
PKGNAMESUFFIX=	-server
DISTNAME=	Canna${PORTVERSION:S/.//g}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Kana-to-Kanji conversion system, binary part
WWW=		https://canna-input.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcanna.so:japanese/canna-lib

USES=		imake tar:xz
USE_RC_SUBR=	canna

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	instserver instclient

DOCS_EN=	ChangeLog README WHATIS
DOCS_JA=	CHANGES.jp README.jp RKCCONF.jp WHATIS.jp
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	    ${MAKEFILE} ${MAKE_ARGS} install.man
	@cd ${STAGEDIR}${PREFIX}/sbin && ${RM} cannakill && \
		${RLN} ../bin/catdic cannakill

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS_EN} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS_JA} ${STAGEDIR}${DOCSDIR}/ja

.include <bsd.port.mk>
