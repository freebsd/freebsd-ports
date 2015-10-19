# Created by: Kirill Bezzubets <kirill@solaris.ru>
# $FreeBSD$

PORTNAME=	gammu
PORTVERSION=	1.33.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CONFLICTS=	gammu-devel-[1-9]* gammu-python-[1-9]*

OPTIONS_DEFINE=	BASH

CMAKE_ARGS+=	-DINSTALL_LIBDATA_DIR=${LOCALBASE}/libdata

USES=		cmake gettext pkgconfig python shebangfix
SHEBANG_FILES=	utils/jadmaker utils/gammu-config
bash_CMD=	/bin/sh
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -i '' -e 's:/etc/bash_completion.d:${PREFIX}/etc/bash_completion.d:' \
		${WRKSRC}/contrib/CMakeLists.txt

post-install:
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

BASH_BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
BASH_RUN_DEPENDS=	${BASH_BUILD_DEPENDS}
BASH_PLIST_FILES=	etc/bash_completion.d/gammu
BASH_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-contrib_CMakeLists.txt

.include <bsd.port.mk>
