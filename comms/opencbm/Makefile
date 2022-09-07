PORTNAME=	opencbm
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Commodore CBM serial IEC/IEEE-488 bus utilities
WWW=		http://opencbm.sourceforge.net/

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	cc65:devel/cc65

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS INFO
OPTIONS_DEFAULT=	DOCS INFO

ALL_TARGET=	opencbm plugin-xu1541 plugin-xum1541
INSTALL_TARGET=	install install-plugin-xu1541 install-plugin-xum1541

DOCS_BUILD_DEPENDS=	dvips:print/tex-dvipsk \
			latex:print/tex-formats \
			linuxdoc:textproc/linuxdoc-tools
DOCS_USES=		ghostscript:build
DOCS_ALL_TARGET=	doc
DOCS_MAKE_ARGS_OFF=	TXT= DVI= PDF= HTML=

INFO_BUILD_DEPENDS=	linuxdoc:textproc/linuxdoc-tools
INFO_USES=		makeinfo
INFO_ALL_TARGET=	doc
INFO_INFO=		opencbm
INFO_MAKE_ARGS_OFF=	INFO=

OCBM_CONFDIR=	${LOCALBASE}/etc/opencbm.conf.d

post-patch:
	@${REINPLACE_CMD} -e 's|_ETC="$$1"|_ETC="$${1:-${LOCALBASE}/etc}"|' \
		-e 's|in /.*/ instead|in ${OCBM_CONFDIR}/ instead|' \
		-e "s|execute 'opencbm_|execute '|" \
		${WRKSRC}/opencbm/LINUX/plugin_helper_tools

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopencbm.so.${OCBM_VERSION}
.for p in xu1541 xum1541
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}${p}.so.${OCBM_VERSION}
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf
	@${MV} ${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf \
		${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf.sample
	@${MV} ${STAGEDIR}${PREFIX}/bin/opencbm_plugin_helper_tools \
		${STAGEDIR}${PREFIX}/sbin/opencbm_plugin_helper_tools

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/opencbm/docs && \
		${COPYTREE_SHARE} "html misc opencbm.pdf opencbm.txt" \
		${STAGEDIR}${DOCSDIR})

post-install-INFO-on:
	${INSTALL_MAN} ${WRKSRC}/opencbm/docs/opencbm.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

.include "Makefile.inc"

.include <bsd.port.mk>
