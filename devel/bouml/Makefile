# New ports collection makefile for:	bouml
# Date created:		14 June 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	bouml
PORTVERSION=	2.28
CATEGORIES=	devel
MASTER_SITES=	http://bouml.free.fr/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}_${PORTREVISION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	BOUML, a free UML 2 modeler

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
QTDIR?=		${QT_PREFIX}
ALL_TARGET=	compile
MAKE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"	\
		QTDIR="${QTDIR}"
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

.if !defined(NOPORTDOCS)
DISTFILES+=	doc${EXTRACT_SUFX}
IGNOREFILES+=	doc${EXTRACT_SUFX}
PORTDOCS=	*
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'	\
		-e 's|%%DESKTOPDIR%%|${DESKTOPDIR}|' ${WRKSRC}/${MAKEFILE}
	${FIND} ${WRKSRC} -name "*.pro" |	\
		${XARGS} ${REINPLACE_CMD} -e '/^CONFIG/s/$$/ thread/'

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${CHMOD} -R ${SHAREMODE} ${DATADIR}/xmi/*
	${FIND} ${DATADIR} -type f -perm 755 | ${XARGS} ${STRIP_CMD}
.if !defined(NOPORTDOCS)
	cd ${WRKDIR}/doc && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKDIR}/doc && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
