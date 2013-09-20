# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.11.4
CATEGORIES=	biology
MASTER_SITES=	http://ugene.unipro.ru/downloads/

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GL=		glu
USE_QT4=	gui webkit xml svg linguist_build moc_build qmake_build \
		qtestlib_build rcc_build uic_build imageformats_run
USE_XORG=	xtst

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
# need to manually tell the build we are on x64
CARCH=		CONFIG+=x64
PLIST_SUB=	NOX64="@comment "
.else
PLIST_SUB=	NOX64=""
.endif

# yes, bash is required, stuff will not execute with sh
post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene

do-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} \
		PREFIX=${PREFIX} INSTALL_PREFIX=${PREFIX} \
		INSTALL_MANDIR=${MAN1PREFIX}/man ${CARCH} \
		UGENE_INSTALL_DATA=${DATADIR} -r ${PORTNAME}.pro

.include <bsd.port.post.mk>
