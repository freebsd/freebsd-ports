# New ports collection makefile for:	gitolite
# Date created:				07-28-2011
# Whom:					milki <milki@rescomp.berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	gitolite
PORTVERSION=	3.01
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://milki.github.com/${PORTNAME}/ \
		LOCAL/tdb

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	An access control layer on top of git

LICENSE=	GPLv2

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

CONFLICTS=	gitolite-[^3]*

USE_PERL5=	yes

SUB_FILES=	pkg-message

OPTIONS=	GITUSER	"Create git user as gitolite provider" On

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GITUSER)
USERS=		git
GROUPS=		${USERS}
PLIST_SUB+=	GITUSER=""
.else
PLIST_SUB+=	GITUSER="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC}/t ${WRKSRC}/src \
		-exec ${GREP} -qs \#\!/usr/bin/perl {} \; \
		-exec ${REINPLACE_CMD} -Ee 's|#!/usr/bin/perl|#!${PERL}|' {} \;

do-build:
	@${MKDIR} ${WRKSRC}/lib
	@${MV} ${WRKSRC}/src/lib/Gitolite ${WRKSRC}/lib/
	@${RMDIR} ${WRKSRC}/src/lib

post-build:
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@(cd ${WRKSRC}/src && ${COPYTREE_BIN} \* ${PREFIX}/libexec/gitolite)
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} Gitolite ${PREFIX}/${SITE_PERL_REL}/)
	@${LN} -s ${PREFIX}/libexec/gitolite/gitolite ${PREFIX}/bin/gitolite

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
