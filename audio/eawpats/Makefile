# Created by: Jonathan Lennox <lennox@cs.columbia.edu>

PORTNAME=	eawpats
PORTVERSION=	12
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	GENTOO
DISTNAME=	eawpats12_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eric A. Welsh's collection of Gravis Ultrasound MIDI patches

# Converted from RESTRICTED
LICENSE=	EAWPATS
LICENSE_NAME=	eawpats
LICENSE_TEXT=	Some of the patches are marked no-commercial-use
LICENSE_PERMS=	auto-accept

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

PATCH_SUBDIRS=	ethnic mazpat/fx gsdrum08 gsdrum25 gsdrum40 gus power sfx wime
DOC_SUBDIRS=	ethnic gsdrum08 gsdrum25 gsdrum40 power wime

WRKSRC=		${WRKDIR}/${PORTNAME}
TIMIDITY_DATADIR=	${PREFIX}/share/timidity

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/home/user/eawpats|${DATADIR}|' ${WRKSRC}/linuxconfig/timidity.cfg

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.cfg ${WRKSRC}/*.pat ${WRKSRC}/*.ini ${STAGEDIR}${DATADIR}
.for subdir in ${PATCH_SUBDIRS}
	${MKDIR} ${STAGEDIR}${DATADIR}/${subdir}
	${INSTALL_DATA} ${WRKSRC}/${subdir}/*.pat ${STAGEDIR}${DATADIR}/${subdir}
.endfor
	${MKDIR} ${STAGEDIR}${TIMIDITY_DATADIR}
	${INSTALL_DATA} ${WRKSRC}/linuxconfig/timidity.cfg ${STAGEDIR}${TIMIDITY_DATADIR}/timidity.cfg-eawpats
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.hlp ${STAGEDIR}${DOCSDIR}
.for subdir in ${DOC_SUBDIRS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${subdir}
	${INSTALL_DATA} ${WRKSRC}/${subdir}/*.txt ${STAGEDIR}${DOCSDIR}/${subdir}
.endfor

.include <bsd.port.mk>
