# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmigemo
PORTVERSION=	20141220
CATEGORIES=	japanese
DIST_SUBDIR=	cmigemo

USE_GITHUB= yes
GH_ACCOUNT= koron
GH_TAGNAME= 6a1c438

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	C implementation of Migemo Japanese incremental search tool

.if !defined(PKGNAMESUFFIX)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE_MIT.txt

RUN_DEPENDS=	${DATADIR}/cp932/migemo-dict:japanese/cmigemo-dict

USE_LDCONFIG=	yes

ALL_TARGET=	gcc-rel gcc-dat
INSTALL_TARGET=	gcc-install

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PORTDOCS=	README_j.txt

.endif

OPTIONS_DEFINE+=DOCS
USES+=		gmake
BUILD_DEPENDS=	${LOCALBASE}/bin/nkf:japanese/nkf

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX) && ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=gcc-install-doc
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/compile/config.mk.in

.include <bsd.port.mk>
