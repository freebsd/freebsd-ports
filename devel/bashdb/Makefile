PORTNAME=	bashdb
DISTVERSION=	5.0-1.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Source-code debugger for bash
WWW=		https://bashdb.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gmake python shebangfix

SHEBANG_FILES=	lib/term-highlight.py

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash

NO_BUILD=	yes
NO_ARCH=	yes

CONFIGURE_ARGS=	--with-bash=${LOCALBASE}/bin/bash
INFO=		bashdb

.include <bsd.port.mk>
