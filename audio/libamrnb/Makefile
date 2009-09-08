# New ports collection makefile for:	libamrnb
# Date created:	30 May 2007
# Whom:		Tatsuki Makino <tatsuki_makino@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	libamrnb
PORTVERSION=	7.0.0.2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://ftp.penguin.cz/pub/users/utx/amr/ \
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.104/:3GPP
DISTNAME=	amrnb-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SRC3GPP}:3GPP
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	3GPP floating-point Adaptive Multi-Rate (AMR) Speech Codec

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	license prohibits redistribution
RESTRICTED_FILES=	${SRC3GPP}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO readme.txt
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LANG=C
MAKE_ENV=	LANG=C
USE_LDCONFIG=	yes

SRC3GPP=	26104-700.zip

post-extract:
	@${CP} ${DISTDIR}/${SRC3GPP} ${WRKSRC}/

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
