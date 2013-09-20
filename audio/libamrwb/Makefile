# Created by: Tatsuki Makino <tatsuki_makino@hotmail.com>
# $FreeBSD$

PORTNAME=	libamrwb
PORTVERSION=	11.0.0.0
CATEGORIES=	audio
MASTER_SITES=	http://ftp.penguin.cz/pub/users/utx/amr/ \
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.204/:3GPP
DISTNAME=	amrwb-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SRC3GPP}:3GPP
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	3GPP Adaptive Multi-Rate - Wideband (AMR-WB) Speech Codec

LICENSE=	BSD

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
RESTRICTED=	license prohibits redistribution
RESTRICTED_FILES=	${SRC3GPP}
USE_BZIP2=	yes
NO_STAGE=	yes
USES=		gmake
USE_AUTOTOOLS=	libtool
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO readme.txt
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LANG=C
MAKE_ENV=	LANG=C
USE_LDCONFIG=	yes
OPTIONS_DEFINE=	DOCS

SRC3GPP=	26204-b00.zip

.include <bsd.port.options.mk>

post-extract:
	@${CP} ${DISTDIR}/${SRC3GPP} ${WRKSRC}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
