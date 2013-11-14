# $FreeBSD$

PORTNAME=	gitolite
PORTVERSION=	3.5.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GH \
		LOCAL/tdb
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	An access control layer on top of git

LICENSE=	GPLv2

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	sitaramc
GH_COMMIT=	926bd5f
GH_TAGNAME=	${GH_COMMIT}

CONFLICTS=	gitolite-[^3]*

USES=		perl5

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GITUSER

GITUSER_DESC=	Create git user as gitolite provider

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGITUSER}
USERS=		git
GROUPS=		${USERS}
PLIST_SUB+=	GITUSER=""
.else
PLIST_SUB+=	GITUSER="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/usr/bin/perl {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/usr/bin/perl|#!${PERL}|' {} \;
	@${FIND} ${WRKSRC} \
		-exec ${GREP} -qs \#\!/bin/bash {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' {} \;

do-build:
	echo "v${PORTVERSION}-0-g${GH_COMMIT}" > ${WRKSRC}/src/VERSION
	@${MKDIR} ${WRKSRC}/lib
	@${MV} ${WRKSRC}/src/lib/Gitolite ${WRKSRC}/lib/
	@${RMDIR} ${WRKSRC}/src/lib
	@${MV} ${WRKSRC}/check-g2-compat ${WRKSRC}/src/
	@${MV} ${WRKSRC}/convert-gitosis-conf ${WRKSRC}/src/

post-build:
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	@(cd ${WRKSRC}/src && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/libexec/gitolite)
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} Gitolite ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/)
	@${LN} -s ${PREFIX}/libexec/gitolite/gitolite ${STAGEDIR}${PREFIX}/bin/gitolite

post-install:
.if ! ${PORT_OPTIONS:MDOCS}
	-@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
.endif

.if ! ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README.txt CHANGELOG
.endif

.include <bsd.port.mk>
