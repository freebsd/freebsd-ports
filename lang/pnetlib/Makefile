# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	pnetlib
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C\# system library for pnet

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		treecc:${PORTSDIR}/lang/treecc

DEPRECATED=	Alpha-quality abandonware - Decommissioned Dec 2012 - Use mono
EXPIRATION=	2014-05-01

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	ChangeLog-1 ChangeLog-2 ChangeLog-3 ChangeLog-4 \
		JScript-embed.txt JScript-internals.txt csunit_howto.html \
		pcf-font-format.txt translating-pnetlib.txt

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11
X11_USE=	XORG=x11

post-patch:
	@${REINPLACE_CMD} 's|$$(LN_S) $$(DESTDIR)$$(libdir)/cscc/lib/$$(FRAMEWORK_VERSION)/pinvoke.map|$$(LN_S) $$(FRAMEWORK_VERSION)/pinvoke.map|' \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} \
		$$ac_aux_dir|$$ac_aux_dir|' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.mk>
