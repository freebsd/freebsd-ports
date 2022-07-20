PORTNAME=	libamrwb
DISTVERSION=	11.0.0.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.penguin.cz/~utx/ftp/amr/ \
		https://www.3gpp.org/ftp/Specs/archive/26_series/26.204/:SRC26204
DISTNAME=	amrwb-${DISTVERSIONFULL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SRC26204}:SRC26204
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	3GPP Adaptive Multi-Rate - Wideband (AMR-WB) Speech Codec

LICENSE=	BSD3CLAUSE 3GPP
LICENSE_COMB=	multi
LICENSE_NAME_3GPP=	3GPP
LICENSE_TEXT_3GPP=	unclear legal status, probably need licenses from 3GPP and more
LICENSE_PERMS_3GPP=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_3GPP=	${SRC26204}
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME}${EXTRACT_SUFX}

USES=		autoreconf gmake tar:bzip2 libtool
USE_LDCONFIG=	yes
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO readme.txt
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

SRC26204=	26204-b00.zip

post-extract:
	@${CP} ${_DISTDIR}/${SRC26204} ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
