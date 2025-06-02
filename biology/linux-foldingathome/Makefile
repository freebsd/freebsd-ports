PORTNAME=	foldingathome
DISTVERSION=	8.4.9
CATEGORIES=	biology linux
MASTER_SITES=	https://download.foldingathome.org/releases/public/fah-client/debian-10-64bit/release/
PKGNAMEPREFIX=	linux-
DISTNAME=	fah-client_${DISTVERSION}-64bit-release

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Folding@home Client
WWW=		https://foldingathome.org/

# Distribution without permission is prohibited
LICENSE=	FAHSL
LICENSE_NAME=	Folding@home Software License
LICENSE_FILE=	${WRKSRC}/${DISTNAME}/LICENSE
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell \
		auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

USES=		linux:rl9 tar:bz2
USE_LINUX=	systemd-libs
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
_FAHCLIENT_PROGRAM=	${PREFIX}/bin/fah-client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/fah-client ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.xml.sample \
		${STAGEDIR}${_FAHCLIENT_CONFIG_XML}.sample
	@${MKDIR} ${STAGEDIR}${_FAHCLIENT_WORK_DIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/${DISTNAME}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
