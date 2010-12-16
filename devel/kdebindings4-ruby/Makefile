# New ports collection makefile for:	kdebindings4-ruby
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt/KDE

LIB_DEPENDS=	smokebase.3:${PORTSDIR}/devel/kdebindings4-smoke \
		okularcore.1:${PORTSDIR}/graphics/kdegraphics4 \
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
.for f in Qt.cpp handlers.cpp marshall.h marshall_types.h qtruby.cpp qtruby.h smokeruby.h
	${REINPLACE_CMD} -e '/include/s,smoke/smoke.h,smoke.h,' ${BUILD_WRKSRC}/qtruby/src/${f}
.endfor

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/${BINDLANG}-${PORTNAME}-env.sh ${PREFIX}/env
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"
.include <bsd.port.mk>
