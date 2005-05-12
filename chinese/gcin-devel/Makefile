# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	0.9.5
CATEGORIES=	chinese
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/

MAINTAINER=	statue@freebsd.netlab.cse.yzu.edu.tw
COMMENT=	A traditional chinese input utility in X

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500034
USE_GCC=	3.4
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
