# $FreeBSD$

PORTNAME=	gitolite
PORTVERSION=	3.6.5
DISTVERSIONPREFIX=v
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access control layer on top of git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	git>=0:devel/git \
		p5-JSON>=0:converters/p5-JSON

USE_GITHUB=	yes
GH_ACCOUNT=	sitaramc

CONFLICTS=	gitolite-[^3]*

USES=		cpe perl5
CPE_VENDOR=	sitaram_chamarty
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GITUSER DOCS
OPTIONS_SUB=	yes

GITUSER_DESC=	Create git user as gitolite provider
GITUSER_VARS=	USERS=git GROUPS=git

post-patch:
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/usr/bin/perl {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/usr/bin/perl|#!${PERL}|' {} \;
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/bin/bash {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' {} \;

do-build:
	echo "${GH_TAGNAME}" > ${WRKSRC}/src/VERSION
	${MKDIR} ${WRKSRC}/lib
	${MV} ${WRKSRC}/src/lib/Gitolite ${WRKSRC}/lib/
	${RMDIR} ${WRKSRC}/src/lib
	${MV} ${WRKSRC}/check-g2-compat ${WRKSRC}/src/
	${MV} ${WRKSRC}/convert-gitosis-conf ${WRKSRC}/src/

post-build:
	${FIND} ${WRKSRC} -name "*.bak" -delete
	${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	(cd ${WRKSRC}/src && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/libexec/gitolite)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} Gitolite ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/)
	${LN} -s ${PREFIX}/libexec/gitolite/gitolite ${STAGEDIR}${PREFIX}/bin/gitolite

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
