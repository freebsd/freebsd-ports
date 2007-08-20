# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
PORTVERSION=	0.13.0
CATEGORIES=	devel kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/${PORTNAME}/${PORTVERSION:R}.x/

MAINTAINER=	yuanjue@FreeBSD.org
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
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

MAN1=	kdesvn.1 kdesvnaskpass.1

post-extract:
	${MKDIR} ${WRKSRC}
.if defined(NOPORTDOCS)
	${RM} -f ${PATCH_WRKSRC}/doc/CMakeLists.txt
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${PATCH_WRKSRC}/doc/CMakeLists.txt
.endif

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${PATCH_WRKSRC})

.include <bsd.port.mk>
