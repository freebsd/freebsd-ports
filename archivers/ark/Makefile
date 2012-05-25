# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ark
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	archivers kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson

CONFLICTS_INSTALL=	kdeutils-4.[0-7].*

USE_XZ=	yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs libkonq
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN1=		ark.1

OPTIONS=	7ZIP "Support for 7-Zip archives in Ark" off \
		RAR "Support for RAR archives in Ark" off \
		ZIP "Support for ZIP archives in Ark" off

.include <bsd.port.options.mk>

.ifdef(WITH_7ZIP)
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

.ifdef(WITH_ZIP)
RUN_DEPENDS+=	unzip>0:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	archive.12:${PORTSDIR}/archivers/libarchive
.endif

.ifdef(WITH_RAR)
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.if ${ARCH} != "amd64" && ${ARCH} != "ia64" && ${ARCH} != "powerpc" && ${ARCH} != "sparc64"
INSTALL_RAR=	YES
.elif ${ARCH} == "amd64"
.ifndef(HAVE_COMPAT_IA32_KERN)
HAVE_COMPAT_IA32_KERN!=	if ${SYSCTL} -n compat.ia32.maxvmem >/dev/null 2>&1; then ${ECHO_CMD} YES; fi
.endif
.if ${HAVE_COMPAT_IA32_KERN} == "YES"
INSTALL_RAR=	YES
.endif
.endif
.ifdef(INSTALL_RAR)
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.endif
.endif

.include <bsd.port.post.mk>
