# New ports collection makefile for:    cdrdao
# Version required:     1.1.1
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $Id: Makefile,v 1.2 1999/05/12 10:38:07 asami Exp $
#
# If You don't want to use Joerg Schilling's SCSI library,
# set DONT_USE_SCGLIB = yes
# If You don't want to use pthead, set DONT_USE_PTHREAD = yes

DISTNAME=		cdrdao-1.1.1.src
PKGNAME=		cdrdao-1.1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.ping.de/sites/daneb/

MAINTAINER=		futatuki@fureai.or.jp

BUILD_DEPENDS=		antlr:${PORTSDIR}/devel/pccts\
			dlg:${PORTSDIR}/devel/pccts

WRKSRC=         	${WRKDIR}/cdrdao-1.1.1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--disable-gtkmmtest
USE_GMAKE=	yes
MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

.if defined(DONT_USE_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+= 	--without-scglib
.endif

.if defined(DONT_USE_PTHREAD) && ${OSVERSION} > 320000
CONFIGURE_ARGS+=	--without-posix-threads
.endif

post-install:
	strip $(PREFIX)/bin/cdrdao
	@${MKDIR} ${PREFIX}/share/doc/cdrdao
.for i in COPYING INSTALL README README.FreeBSD README.PlexDAE
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/cdrdao/
.endfor
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
