PORTNAME=	libstdc++_stldoc_4.2.2
PORTVERSION=	20071101
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	GCC/libstdc++/doxygen
DISTNAME=	libstdc++-html-USERS-4.2.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU libstdc++ API documentation

USES=		tar:bzip2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# This port contains too many pathnames to use for globs.
# PORTDOCS does not do the right thing when a single directory '.'
# is specified, so use a directory name.

PORTDOCS=	stldoc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/stldoc
	(cd ${WRKSRC}/html_user-4.2.20071101 && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/stldoc)
.else
	@${ECHO} "Enable the DOCS option to install documentation -- installing nothing."
.endif

.include <bsd.port.mk>
