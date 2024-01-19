PORTNAME=	baudline
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	audio linux
# We did have permission from author Erik Olsen <erik@sigblips.net> for the
# package cluster to automatically fetch baudline
MASTER_SITES=	http://www.baudline.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	baudline_${PORTVERSION:S/.p/pre/}_linux_i686

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Real-time signal analysis and time-frequency browser
WWW=		https://www.baudline.com/

# Converted from RESTRICTED
LICENSE=	BAUDLINE
LICENSE_NAME=	baudline
LICENSE_TEXT=	author requests no distribution except from their site
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/${DISTNAME:S/i686/x86/}
USES=		linux
USE_LINUX=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README_unix.txt
PLIST_FILES=	bin/baudline

OPTIONS_DEFINE=		DOCS MPG123
OPTIONS_DEFAULT=	MPG123

MPG123_RUN_DEPENDS=	mpg123:audio/mpg123

.include <bsd.port.pre.mk>
DEPRECATED=	upstream has gone to subscription model and no longer distributes this version. Try comms/Inspectrum or audio/xanalyser instead
EXPIRATION_DATE=	2024-02-01
IGNORE=		upstream has removed distribution

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/baudline

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/baudline ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
