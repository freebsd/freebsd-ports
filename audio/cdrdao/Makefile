# New ports collection makefile for:    cdrdao
# Version required:     1.1.0
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $Id$
#
# If You don't want to use Joerg Schilling's SCSI library,
# set DONT_USE_SCGLIB = yes

DISTNAME=		cdrdao-1.1.0.src
PKGNAME=		cdrdao-1.1.0
CATEGORIES=		cdrdao
MASTER_SITES=		http://www.ping.de/sites/daneb/

MAINTAINER=		futatuki@fureai.or.jp

BUILD_DEPENDS=		antlr:${PORTSDIR}/devel/pccts\
			dlg:${PORTSDIR}/devel/pccts

WRKSRC=         	${WRKDIR}/cdrdao-1.1.0

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--disable-gtkmmtest
USE_GMAKE=	yes
MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

.if defined(DONT_USE_SCGLIB) && ${OSVERSION} >= 300000
CONFIGURE_ARGS+= 	--without-scglib
.endif

post-install:
	strip $(PREFIX)/bin/cdrdao
	@${MKDIR} ${PREFIX}/share/doc/cdrdao
.for i in COPYING INSTALL README README.FreeBSD README.PlexDAE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/cdrdao/
.endfor
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
