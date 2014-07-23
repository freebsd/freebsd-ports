# Created by: Jonathan Lennox <lennox@cs.columbia.edu>
# $FreeBSD$

PORTNAME=	eawpats
PORTVERSION=	12
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	eawpats12_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eric A. Welsh's collection of Gravis Ultrasound MIDI patches

RESTRICTED=	Some of the patches are marked no-commercial-use

NO_BUILD=	yes

PATCH_SUBDIRS=	ethnic mazpat/fx gsdrum08 gsdrum25 gsdrum40 gus power sfx wime
DOC_SUBDIRS=	ethnic gsdrum08 gsdrum25 gsdrum40 power wime

WRKSRC=		${WRKDIR}/${PORTNAME}
TIMIDITY_DATADIR=	${PREFIX}/share/timidity

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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
	[ -f ${STAGEDIR}${TIMIDITY_DATADIR}/timidity.cfg ] || \
		${INSTALL_DATA} ${WRKSRC}/linuxconfig/timidity.cfg ${STAGEDIR}${TIMIDITY_DATADIR}/timidity.cfg
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/*.txt ${WRKSRC}/*.hlp ${STAGEDIR}${DOCSDIR}
.for subdir in ${DOC_SUBDIRS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${subdir}
	${INSTALL_MAN} ${WRKSRC}/${subdir}/*.txt ${STAGEDIR}${DOCSDIR}/${subdir}
.endfor

.include <bsd.port.mk>
