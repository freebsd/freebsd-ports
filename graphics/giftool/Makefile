# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	giftool
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.the-labs.com/GIFTool/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for GIF89a transparent option and interlace mode

NO_CDROM=	Shareware

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool
MAKE_ARGS=	CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=	RETVALUE MALLOCSIZE DOCS
OPTIONS_DEFAULT=	RETVALUE MALLOCSIZE
RETVALUE_DESC=	Return value patch
MALLOCSIZE_DESC=	Improve malloc size

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYRIGHT README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRETVALUE}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa
.endif
.if ${PORT_OPTIONS:MMALLOCSIZE}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ab
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftool ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
