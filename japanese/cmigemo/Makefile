PORTNAME=	cmigemo
PORTVERSION=	20141220
CATEGORIES=	japanese
DIST_SUBDIR=	cmigemo

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	C implementation of Migemo Japanese incremental search tool

.if !defined(PKGNAMESUFFIX)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE_MIT.txt

RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/cp932/migemo-dict:japanese/cmigemo-dict

USE_LDCONFIG=	yes

ALL_TARGET=	gcc-rel gcc-dat
INSTALL_TARGET=	gcc-install

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PORTDOCS=	README_j.txt
.endif

BUILD_DEPENDS=	${LOCALBASE}/bin/nkf:japanese/nkf

USES+=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	koron
GH_TAGNAME=	6a1c438

OPTIONS_DEFINE+=DOCS

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX) && ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=gcc-install-doc
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/compile/config.mk.in

.include <bsd.port.mk>
