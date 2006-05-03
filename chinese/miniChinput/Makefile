# New ports collection makefile for:    zh-miniChinput
# Date created:		19 Jul 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	miniChinput
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	minichinput

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny version of Chinput

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XLIB=	yes
ALL_TARGET=	all data
INSTALL_TARGET=	install data-install

MAN1=		chinput.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Build fails on sparc64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,make,${GMAKE},g' ${WRKSRC}/src/Makefile.in
	@echo "install:" >> ${WRKSRC}/src/IMdkit/Makefile
	@${REINPLACE_CMD} -e 's#$$(prefix)$$(imdir)/{gb,gbk,big5}#$$(prefix)$$(imdir)/gb $$(prefix)$$(imdir)/gbk $$(prefix)$$(imdir)/big5#g' ${WRKSRC}/ImmModules/turbo/Makefile.in
	@${REINPLACE_CMD} -e 's,-@PACKAGE_VERSION@,,g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's,/share/man,/man,g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
