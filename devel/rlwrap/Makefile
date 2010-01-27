# ex:ts=8
# New ports collection makefile for:	rlwrap
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rlwrap
PORTVERSION=	0.36
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice

MAINTAINER=	gamato@users.sf.net
COMMENT=	Readline wrapper

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ptyttylib_cv_ptys=BSD LDFLAGS=-lutil

MAN1=	rlwrap.1
MAN3=	RlwrapFilter.3pm

PORTDOCS=	AUTHORS BUGS NEWS PLEA README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
