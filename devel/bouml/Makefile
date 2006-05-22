# New ports collection makefile for:	bouml
# Date created:		14 June 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	bouml
PORTVERSION=	2.14.4
CATEGORIES=	devel
MASTER_SITES=	http://bouml.free.fr/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	BOUML, a free UML tool box

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
QTDIR?=		${X11BASE}
ALL_TARGET=	compile
MAKE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"	\
		QTDIR="${QTDIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

.if !defined(NOPORTDOCS)
DISTFILES+=	doc${EXTRACT_SUFX}
IGNOREFILES+=	doc${EXTRACT_SUFX}
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile with gcc-2.95
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${MAKEFILE}
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

.include <bsd.port.post.mk>
