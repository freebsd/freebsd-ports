# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.27.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CONFLICTS=	gammu-devel-[1-9]* gammu-python-[1-9]*

CMAKE_ARGS+=	-DINSTALL_LIBDATA_DIR=${LOCALBASE}/libdata

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

post-patch:
	@${REINPLACE_CMD} -i '' -e 's:bash:sh:' -e 's:dialog:cdialog:' ${WRKSRC}/utils/gammu-config
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e 's@ -Wno-pointer-sign@@g' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
