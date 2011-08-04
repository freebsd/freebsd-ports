# New ports collection makefile for:	baudline
# Date created:				19 Jan 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	baudline
PORTVERSION=	1.08
CATEGORIES=	audio linux
# We have permission from author Erik Olsen <erik@sigblips.net> for the
# package cluster to automatically fetch baudline
MASTER_SITES=	http://www.baudline.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	baudline_${PORTVERSION:S/.p/pre/}_linux_${ARCH_SUFX}
EXTRACT_SUFX=	.tar

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Real-time signal analysis and time-frequency browser

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/${DISTNAME:S/i686/x86/}
ARCH_SUFX=	${ARCH:S/i386/x86/:S/amd64/x86_64/}
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

RESTRICTED=	author requests no distribution except from their site

PORTDOCS=	README_unix.txt
PLIST_FILES=	bin/baudline

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
	@${INSTALL_PROGRAM} ${WRKSRC}/baudline ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	@[ -f /compat/linux/proc/stat ] || ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
