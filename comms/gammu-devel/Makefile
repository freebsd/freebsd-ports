# New ports collection makefile for:	gammu-devel
# Date created:		2009-10-15
# Whom:			Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.26.90
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/
PKGNAMESUFFIX=	-devel

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities - Development version

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CMAKE_ARGS+=	-DINSTALL_LIBDATA_DIR=${PREFIX}/libdata

USE_CMAKE=	yes
USE_GNOME=	pkgconfig

.if defined(WITH_PYTHON_GAMMU)
USE_PYTHON=	YES
PLIST_SUB=	WITH_PYTHON_GAMMU=""
.else
PLIST_SUB=	WITH_PYTHON_GAMMU="@comment "
.endif

PORTDOCS=	*

.if defined(NOPORTDOCS)
CMAKE_ARGS+=	-DINSTALL_DOC=OFF -DINSTALL_PHP_EXAMPLES=OFF -DINSTALL_MEDIA=OFF \
		-DINSTALL_GNAPPLET=OFF
.else
MAN1=		gammu.1 gammu-config.1 jadmaker.1 gammu-smsd.1 gammu-smsd-inject.1 \
		gammu-smsd-monitor.1
MAN5=		gammu-smsdrc.5 gammurc.5
MAN7=		gammu-smsd-files.7 gammu-smsd-mysql.7 gammu-smsd-pgsql.7 \
		gammu-smsd-dbi.7 gammu-smsd-tables.7
.endif

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64" || ${ARCH} == "sparc64")
USE_GCC=	4.3
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's:bash:sh:' -e 's:dialog:cdialog:' ${WRKSRC}/utils/gammu-config
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e 's@ -Wno-pointer-sign@@g' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
