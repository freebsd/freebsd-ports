# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	foldingathome
DISTVERSION=	7.5.1-1
PORTREVISION=	2
CATEGORIES=	biology linux
MASTER_SITES=	https://download.foldingathome.org/releases/public/release/fahclient/centos-6.7-64bit/v${DISTVERSION:R}/
PKGNAMEPREFIX=	linux-
DISTNAME=	fahclient-${DISTVERSION}
EXTRACT_SUFX=	.x86_64.rpm

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Folding@home Client

LICENSE=	FAHSL
LICENSE_NAME=	Folding@home Software License
LICENSE_FILE=	${WRKSRC}/usr/share/doc/fahclient/copyright
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell \
		auto-accept

LEGAL_TEXT=	Distribution without permission is prohibited

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	The i386 client has not been ported

USES=		dos2unix linux
DOS2UNIX_FILES=	usr/share/doc/fahclient/*
USE_RC_SUBR=	fahclient

ETCDIR=		${PREFIX}/etc/fahclient
DOCSDIR=	${PREFIX}/share/doc/fahclient
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	FAHCLIENT_CONFIG_XML=${_FAHCLIENT_CONFIG_XML} \
		FAHCLIENT_PROGRAM=${_FAHCLIENT_PROGRAM} \
		FAHCLIENT_WORK_DIR=${_FAHCLIENT_WORK_DIR}
NO_WRKSUBDIR=	yes

USERS=		fahclient
GROUPS=		fahclient

PLIST_SUB=	FAHCLIENT_WORK_DIR=${_FAHCLIENT_WORK_DIR}

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

_FAHCLIENT_CONFIG_XML=	${ETCDIR}/config.xml
_FAHCLIENT_WORK_DIR=	/var/db/fahclient
_FAHCLIENT_PROGRAM=	${PREFIX}/bin/FAHClient

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/FAHClient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/FAHCoreWrapper ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/usr/share/doc/fahclient/sample-config.xml \
		${STAGEDIR}${_FAHCLIENT_CONFIG_XML}.sample
	@${MKDIR} ${STAGEDIR}${_FAHCLIENT_WORK_DIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/usr/share/doc/fahclient/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
