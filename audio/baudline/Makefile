# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	baudline
PORTVERSION=	1.08
CATEGORIES=	audio linux
# We have permission from author Erik Olsen <erik@sigblips.net> for the
# package cluster to automatically fetch baudline
MASTER_SITES=	http://www.baudline.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	baudline_${PORTVERSION:S/.p/pre/}_linux_i686

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Real-time signal analysis and time-frequency browser

WRKSRC=		${WRKDIR}/${DISTNAME:S/i686/x86/}
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	author requests no distribution except from their site

PORTDOCS=	README_unix.txt
PLIST_FILES=	bin/baudline

OPTIONS_DEFINE=		MPG123
OPTIONS_DEFAULT=	MPG123

MMPG123_RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		may not be automatically fetched due to licensing\
		restrictions. You must manually fetch ${DISTFILES} from\
		http://www.baudline.com/download.html. Once ${DISTFILES}\
		has been downloaded, move it to ${DISTDIR} and then\
		restart this build
.endif

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/baudline

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/baudline ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif
	@[ -f /compat/linux/proc/stat ] || ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
