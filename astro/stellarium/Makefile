# New ports collection makefile for:	Stellarium
# Date created:				26 Jan 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	stellarium
PORTVERSION=	0.10.6
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Stellarium-sources/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY:=	${DISTFILES}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A 3D photo-realistic sky renderer

LICENSE=	GPLv2

USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build rcc_build uic_build qmake_build \
		corelib gui network opengl script
MAKE_JOBS_SAFE=	yes

MAN1=		stellarium.1
PORTDOCS=	AUTHORS ChangeLog README

DESKTOP_ENTRIES="Stellarium" "View the sky" \
		"${DATADIR}/data/stellarium.ico" "${PORTNAME}" \
		"Application;Astronomy;Education;Science;" ${FALSE}

OPTIONS=	MORE_STARS	"Install extra star catalogs (1.2GB)"	off

.include <bsd.port.options.mk>

.if defined(WITH_MORE_STARS)
.for i in 4 5 6 7 8
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars${i}:stars${i}
.endfor
DISTFILES+=	stars_4_1v0_0.cat:stars4 stars_5_2v0_0.cat:stars5 \
		stars_6_2v0_0.cat:stars6 stars_7_2v0_0.cat:stars7 \
		stars_8_2v0_0.cat:stars8
PLIST_SUB+=	MORE_STARS=""
.else
PLIST_SUB+=	MORE_STARS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/typedef.*void.*__GLXextFuncPtr/d' \
		${WRKSRC}/src/core/external/GLee.h
	@${REINPLACE_CMD} -e '/QTTEST/d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/doc/CMakeLists.txt
# avoid picking up the wrong `fixx11h.h' (x11/kdelibs3 port installs one that
# doesn't handle FontChange)
	@${FIND} ${WRKSRC}/src ${WRKSRC}/plugins -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/fixx11h\.h/fixx11qt4h.h/'
	@cd ${WRKSRC}/src/core/external && ${MV} fixx11h.h fixx11qt4h.h

post-install:
.if defined(WITH_MORE_STARS)
	${INSTALL_DATA} ${DISTDIR}/stars_[45678]_[12]v0_0.cat \
		${DATADIR}/stars/default
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
