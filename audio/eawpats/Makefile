# New ports collection makefile for:   eawpats
# Date created:        3 September 2003
# Whom:                Jonathan Lennox <lennox@cs.columbia.edu>
#
# $FreeBSD$
#

PORTNAME=	eawpats
PORTVERSION=	12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	eawpats12_full
EXTRACT_SUFX=	.rar

MAINTAINER=	lennox@cs.columbia.edu
COMMENT=	Eric A. Welsh's collection of Gravis Ultrasound MIDI patches

BROKEN=		Unfetchable

EXTRACT_DEPENDS=unrar:${PORTSDIR}/archivers/unrar
# Not useful without timidity.
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity++

RESTRICTED=	Some of the patches are marked no-commercial-use

NO_BUILD=	yes
USE_REINPLACE=	yes

PATCH_SUBDIRS=	ethnic mazpat/fx gsdrum08 gsdrum25 gsdrum40 gus power sfx wime
DOC_SUBDIRS=	ethnic gsdrum08 gsdrum25 gsdrum40 power wime

WRKSRC=		${WRKDIR}
TIMIDITY_DATADIR=	${PREFIX}/share/timidity

EXTRACT_CMD=	unrar
EXTRACT_BEFORE_ARGS=x
EXTRACT_AFTER_ARGS=

post-patch:
	@${REINPLACE_CMD} -e 's|c:\\timidity|${DATADIR}|;s|c:\\eawpats|${DATADIR}|' ${WRKSRC}/timidity.cfg

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.cfg ${WRKSRC}/*.pat ${WRKSRC}/*.ini ${DATADIR}
.for subdir in ${PATCH_SUBDIRS}
	${MKDIR} ${DATADIR}/${subdir}
	${INSTALL_DATA} ${WRKSRC}/${subdir}/*.pat ${DATADIR}/${subdir}
.endfor
	${MKDIR} ${TIMIDITY_DATADIR}
	${INSTALL_DATA} ${WRKSRC}/timidity.cfg ${TIMIDITY_DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/*.txt ${WRKSRC}/*.hlp ${DOCSDIR}
.for subdir in ${DOC_SUBDIRS}
	${MKDIR} ${DOCSDIR}/${subdir}
	${INSTALL_MAN} ${WRKSRC}/${subdir}/*.txt ${DOCSDIR}/${subdir}
.endfor
.endif

.include <bsd.port.mk>
