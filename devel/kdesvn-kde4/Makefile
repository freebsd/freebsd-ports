# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
PORTVERSION=	0.14.1
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	http://www.alwins-world.de/programs/download/${PORTNAME}/${PORTVERSION:R}.x/

MAINTAINER=	yuanjue@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr-svn \
		svn_client-1:${PORTSDIR}/devel/subversion \
		neon:${PORTSDIR}/www/neon26

USE_CMAKE=	yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
EXTRA_PATCHES=	${FILESDIR}/nls-patch-CMakeLists.txt
.endif

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

MAN1=	kdesvn.1 kdesvnaskpass.1

post-extract:
	${MKDIR} ${WRKSRC}
.if defined(NOPORTDOCS)
	${RM} -f ${PATCH_WRKSRC}/doc/CMakeLists.txt
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${PATCH_WRKSRC}/doc/CMakeLists.txt
.endif

.include <bsd.port.mk>
