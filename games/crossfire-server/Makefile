# Created by: Jasper Jongmans <j.jongmans@aprogas.net>
# $FreeBSD$

PORTNAME=	crossfire
PORTVERSION=	1.71.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-server/${PORTVERSION} \
		SF/${PORTNAME}/${PORTNAME}-arch/${PORTVERSION}:arch \
		SF/${PORTNAME}/${PORTNAME}-maps/${PORTVERSION}:maps
PKGNAMESUFFIX=	-server
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}.arch${EXTRACT_SUFX}:arch \
		${DISTNAME}.maps${EXTRACT_SUFX}:maps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server for multiplayer graphical arcade and adventure game

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool perl5 python:2.7 shebangfix tar:bzip2 \
		uidfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-check=no --localstatedir=/var/games
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PKGNAME}

SHEBANG_FILES=	../maps/Info/*.pl ../maps/brest/pshops/pshop_copier \
		doc/*.pl doc/playbook/*.pl doc/scripts/*.pl \
		lib/adm/*.pl lib/adm/map_info utils/*.in utils/mktable.script

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	CFLOGGER CFNEWSPAPER CFRHG
OPTIONS_SUB=		yes

CFLOGGER_DESC=		SQLite logging plugin
CFLOGGER_USES=		sqlite:3
CFLOGGER_CONFIGURE_ON=	--enable-logger=yes
CFNEWSPAPER_DESC=	Newspaper plugin
CFNEWSPAPER_CONFIGURE_ON=	--enable-newspaper=yes
CFRHG_DESC=		Random house genetor plugin
CFRHG_CONFIGURE_ON=	--enable-cfrhg=yes

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.am' | ${XARGS} ${REINPLACE_CMD} -e \
		's|=-ldl|=|'
	@${REINPLACE_CMD} -e \
		's|exec /usr/bin/perl|exec ${LOCALBASE}/bin/perl|' \
		${WRKSRC}/doc/scripts/*-extract.pl
	@${REINPLACE_CMD} -e \
		'/PYTHON_CHECK_VERSIONS/s|=".*"|="${PYTHON_VER}"|' \
		${WRKSRC}/macros/cf_python.m4

pre-configure:
	@${CHMOD} 644 ${WRKSRC}/macros/*.m4

pre-build:
	@${LN} -sf ../../arch ${WRKSRC}/lib

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/maps
	(cd ${WRKDIR}/maps && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/maps)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/doc "! -name '*Makefile*'")

.include <bsd.port.mk>
