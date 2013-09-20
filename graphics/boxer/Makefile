# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	boxer
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	box
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GUI for Box the figure description language

LICENSE=	GPLv3

RUN_DEPENDS=	box:${PORTSDIR}/graphics/box

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_LDCONFIG=	yes

PORTDOCS=	ChangeLog
PORTEXAMPLES=	*

DESKTOP_ENTRIES="Boxer" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Application;Graphics;" false

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/src/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
