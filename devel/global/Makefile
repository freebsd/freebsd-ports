# New ports collection makefile for:	global
# Date created:		20 June 2000
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	global
PORTVERSION=	4.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.tamacom.com/global/

MAINTAINER=	josb@cncdsl.com

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		htags.1 btreeop.1 gtags.1 global.1 gctags.1

post-patch:
	${PERL} -pi -e "s|\@PERL\@|${PERL}|g" ${WRKSRC}/htags/htags.in

post-install:
	install-info ${PREFIX}/info/global.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/global
.for file in AUTHORS COPYING ChangeLog FAQ INSTALL LICENSE NEWS README \
		THANKS
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/global
.endfor
.endif

.include <bsd.port.mk>
