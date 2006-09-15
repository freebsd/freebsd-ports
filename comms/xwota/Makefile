# New ports collection makefile for:	xwota
# Date created:				September 13 2006
# Whom:					Diane Bruce <db@db.net
#
# $FreeBSD$
#

PORTNAME=	xwota
PORTVERSION=	0.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://people.fabaris.it/iz0ete/xwota/

MAINTAINER=	db@db.net
COMMENT=	X version of who is on the air

USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15

post-install:
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for	d in ${WRKSRC}/README \
	${WRKSRC}/COPYING \
	${WRKSRC}/AUTHORS \
	${WRKSRC}/ChangeLog \
	${WRKSRC}/INSTALL \
	${WRKSRC}/NEWS \
	${WRKSRC}/TODO
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "xwota docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build 4.x
.endif

.include <bsd.port.post.mk>
