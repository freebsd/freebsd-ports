# New ports collection makefile for:   giftool
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	giftool
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.the-labs.com/GIFTool/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for GIF89a transparent option and interlace mode

NO_CDROM=	"Shareware"

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool
MAKE_ARGS=	CFLAGS="${CFLAGS}"

OPTIONS=	RETVALUE "Return value patch" on \
		MALLOCSIZE "Improve malloc size" on

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYRIGHT README

.include <bsd.port.pre.mk>

.if defined(WITH_RETVALUE)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa
.endif
.if defined(WITH_MALLOCSIZE)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ab
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftool ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
