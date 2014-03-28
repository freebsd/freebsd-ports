# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	libamrnb
PORTVERSION=	11.0.0.0
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.penguin.cz/~utx/ftp/amr/ \
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.104/:SRC26104
DISTNAME=	amrnb-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SRC26104}:SRC26104
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	3GPP floating-point Adaptive Multi-Rate (AMR) Speech Codec

LICENSE=	BSD3CLAUSE 3GPP
LICENSE_COMB=	dual
LICENSE_NAME_3GPP=	3GPP
LICENSE_TEXT_3GPP=	${RESTRICTED}
LICENSE_PERMS_3GPP=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_3GPP=	${SRC26104}

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	unclear legal status, probably need licenses from 3GPP and more

USES=		gmake tar:bzip2
USE_AUTOTOOLS=	libtool
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO readme.txt
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LANG=C
MAKE_ENV+=	LANG=C
USE_LDCONFIG=	yes
OPTIONS_DEFINE=	DOCS

SRC26104=	26104-b00.zip

.include <bsd.port.options.mk>

post-extract:
	@${CP} ${_DISTDIR}/${SRC26104} ${WRKSRC}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
