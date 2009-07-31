# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	http://kdesvn.alwins-world.de/downloads/

MAINTAINER=	yuanjue@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion \
		neon:${PORTSDIR}/www/neon28

USE_CMAKE=	yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_SQLITE=	3

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
EXTRA_PATCHES=	${FILESDIR}/nls-patch-CMakeLists.txt
.endif

BROKEN=		fails to build

DOCSDIR=	${PREFIX}/share/doc

MAN1=	kdesvn.1 kdesvnaskpass.1

post-extract:
	${MKDIR} ${WRKSRC}
.if defined(NOPORTDOCS)
	${RM} -f ${PATCH_WRKSRC}/doc/CMakeLists.txt
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${PATCH_WRKSRC}/doc/CMakeLists.txt
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
BROKEN=		Leaves files behind when deinstalled on amd64
.endif
.if ${ARCH} == sparc64
BROKEN=		Fails to install on sparc64
.endif

.include <bsd.port.post.mk>
