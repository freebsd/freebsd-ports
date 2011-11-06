# New ports collection makefile for:	gammu-devel
# Date created:		2009-10-15
# Whom:			Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.29.92
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/
PKGNAMESUFFIX=	-devel

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities - Development version

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CONFLICTS=	gammu-[1-9]* gammu-python-[1-9]*

LICENSE=	GPLv2

CMAKE_ARGS+=	-DINSTALL_LIBDATA_DIR=${LOCALBASE}/libdata

USE_CMAKE=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_BZIP2=	yes

PORTDOCS=	*

.if defined(NOPORTDOCS)
CMAKE_ARGS+=	-DINSTALL_DOC=OFF -DINSTALL_PHP_EXAMPLES=OFF -DINSTALL_MEDIA=OFF
.else
MAN1=		gammu.1 gammu-config.1 jadmaker.1 gammu-smsd.1 gammu-smsd-inject.1 \
		gammu-smsd-monitor.1 gammu-detect.1
MAN5=		gammu-backup.5 gammu-smsbackup.5 gammu-smsdrc.5 gammurc.5
MAN7=		gammu-smsd-files.7 gammu-smsd-mysql.7 gammu-smsd-pgsql.7 \
		gammu-smsd-dbi.7 gammu-smsd-tables.7 gammu-smsd-null.7 \
		gammu-smsd-run.7 gammu-smsd-odbc.7 gammu-smsd-sql.7

.endif

post-install:
.for opt in -Qold -O
	${PYTHON_CMD} ${opt} -m compileall -l ${PYTHONPREFIX_SITELIBDIR}/gammu
.endfor

post-patch:
	@${REINPLACE_CMD} -i '' -e 's:bash:sh:' -e 's:dialog:cdialog:' ${WRKSRC}/utils/gammu-config

.include <bsd.port.mk>
