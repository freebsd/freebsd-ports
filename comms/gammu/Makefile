# Created by: Kirill Bezzubets <kirill@solaris.ru>
# $FreeBSD$

PORTNAME=	gammu
PORTVERSION=	1.33.0
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CONFLICTS=	gammu-devel-[1-9]* gammu-python-[1-9]*

OPTIONS_DEFINE=	BASH

CMAKE_ARGS+=	-DINSTALL_LIBDATA_DIR=${LOCALBASE}/libdata

USES=		cmake gettext
USE_PYTHON=	yes
USE_GNOME=	glib20

PORTDOCS=	*

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -i '' -e 's:bash:sh:' -e 's:dialog:cdialog:' ${WRKSRC}/utils/gammu-config
	@${REINPLACE_CMD} -i '' -e 's:/etc/bash_completion.d:${PREFIX}/etc/bash_completion.d:' \
		${WRKSRC}/contrib/CMakeLists.txt

post-install:
.for opt in -Qold -O
	${PYTHON_CMD} ${opt} -m compileall -l ${PYTHONPREFIX_SITELIBDIR}/gammu
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
PLIST_FILES+=	etc/bash_completion.d/gammu
PLIST_DIRSTRY+=	etc/bash_completion.d
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-contrib_CMakeLists.txt
.endif

.if ${PORT_OPTIONS:MDOCS}
MAN1=		gammu.1 gammu-config.1 jadmaker.1 gammu-smsd.1 gammu-smsd-inject.1 \
		gammu-smsd-monitor.1 gammu-detect.1
MAN5=		gammu-backup.5 gammu-smsbackup.5 gammu-smsdrc.5 gammurc.5
MAN7=		gammu-smsd-files.7 gammu-smsd-mysql.7 \
		gammu-smsd-odbc.7 gammu-smsd-pgsql.7 \
		gammu-smsd-dbi.7 gammu-smsd-tables.7 gammu-smsd-null.7 \
		gammu-smsd-run.7 gammu-smsd-sql.7
.else
CMAKE_ARGS+=	-DINSTALL_DOC=OFF -DINSTALL_PHP_EXAMPLES=OFF -DINSTALL_MEDIA=OFF \
		-DINSTALL_GNAPPLET=OFF
.endif

.include <bsd.port.mk>
