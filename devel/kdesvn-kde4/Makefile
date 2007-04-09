# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
PORTVERSION=	0.11.2
CATEGORIES=	devel kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/${PORTNAME}/ \
		http://www.yuanjue.net/download/

MAINTAINER=	yuanjue@yuanjue.net
COMMENT=	KDE frontend for Subversion

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

WRKSRC=		${WRKDIR}/${DISTNAME}-build
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr-svn \
		svn_client-1:${PORTSDIR}/devel/subversion \
		neon:${PORTSDIR}/www/neon

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

MAN1=	kdesvn.1 kdesvnaskpass.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

post-extract:
	${MKDIR} ${WRKSRC}

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${PATCH_WRKSRC})

.include <bsd.port.post.mk>
