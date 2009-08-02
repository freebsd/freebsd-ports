# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnetlib
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	C\# system library for pnet

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		treecc:${PORTSDIR}/lang/treecc

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	ChangeLog-1 ChangeLog-2 ChangeLog-3 ChangeLog-4 \
	JScript-embed.txt JScript-internals.txt csunit_howto.html \
	pcf-font-format.txt translating-pnetlib.txt

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
IGNORE=		coredump during build on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
