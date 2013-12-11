# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ark
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	archivers kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

LIB_DEPENDS=	libqjson.so:${PORTSDIR}/devel/qjson

CONFLICTS_INSTALL=	kdeutils-4.[0-7].*

NO_STAGE=	yes
USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs libkonq
USES=		cmake:outsource
USE_QT4=	qtestlib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

MAN1=		ark.1

OPTIONS_DEFINE=	7ZIP RAR ZIP

7ZIP_DESC=	Support for 7-Zip archives
RAR_DESC=	Support for RAR archives
ZIP_DESC=	Support for ZIP archives

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M7ZIP}
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

.if ${PORT_OPTIONS:MZIP}
RUN_DEPENDS+=	unzip>0:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	libarchive.so:${PORTSDIR}/archivers/libarchive
.endif

.if ${PORT_OPTIONS:MRAR}
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
