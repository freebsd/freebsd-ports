# New ports collection makefile for:	tcsh with multibyte support enabled
# Date created:		29 November 1997
# Whom:			Issei Suzuki <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcsh
PORTVERSION=	6.08.05
CATEGORIES=	japanese shells
MASTER_SITES=	ftp://ftp.astron.com/pri/

MAINTAINER=	issei@jp.FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500006 || ${OSVERSION} < 500000 && ${OSVERSION} >= 400021
FORBIDDEN=	"Japanese support is already in the base system"
.endif

GNU_CONFIGURE=	yes
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man
MAN1= 		tcsh.1
PORTDOCS=	FAQ Fixes README WishList complete.tcsh

post-install:
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} tcsh.C.cat ${PREFIX}/share/nls/C/tcsh.cat; \
	${INSTALL_DATA} tcsh.C.m ${PREFIX}/share/nls/C/tcsh.m; \
	)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tcsh
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/tcsh/
.endfor
.endif
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/tcsh) >/etc/shells
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
