# New ports collection makefile for:	kdebindings4-ruby
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt/KDE

LIB_DEPENDS=	smokebase.3:${PORTSDIR}/devel/kdebindings4-smoke \
		okularcore.1:${PORTSDIR}/graphics/kdegraphics4 \
		kateinterfaces.5:${PORTSDIR}/devel/kdesdk4 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

BINDLANG=	ruby

USE_RUBY=	yes
USE_KDE4=	pimlibs
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

BUILD_WRKSRC=	${WRKSRC}/${BINDLANG}

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

SUB_FILES=	${BINDLANG}-${PORTNAME}-env.sh pkg-message
SUB_LIST+=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR} \
		RUBY_SITEARCHLIBDIR=${RUBY_SITEARCHLIBDIR}

post-patch:
.for f in Qt.cpp handlers.cpp marshall.h marshall_types.h marshall_types.cpp qtruby.cpp qtruby.h smokeruby.h
	${REINPLACE_CMD} -e '/include/s,smoke/smoke.h,smoke.h,'  ${BUILD_WRKSRC}/qtruby/src/${f}
.endfor
	${GREP} -H -r "#include <smoke" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -e '/include/s,smoke/qt/,smoke/,' -e '/include/s,smoke/kde/,smoke/,'

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/${BINDLANG}-${PORTNAME}-env.sh ${PREFIX}/env
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"
.include <bsd.port.pre.mk>

#KrossRuby is broken with Ruby 1.9, see http://bugs.kde.org/243565
.if ${RUBY_VER} == 1.9
CMAKE_ARGS+=	-DENABLE_KROSSRUBY=OFF
PLIST_SUB+=	KROSS="@comment "
.else
PLIST_SUB+=	KROSS=""
.endif

.include <bsd.port.post.mk>
