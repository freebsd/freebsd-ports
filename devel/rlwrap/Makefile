# Created by: ijliao
# $FreeBSD$

PORTNAME=	rlwrap
PORTVERSION=	0.37
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice

MAINTAINER=	gamato@users.sf.net
COMMENT=	Readline wrapper

GNU_CONFIGURE=		yes

MAN1=	rlwrap.1
MAN3=	RlwrapFilter.3pm

PORTDOCS=	AUTHORS BUGS NEWS PLEA README TODO

post-patch:	.SILENT
	${REINPLACE_CMD} 's|/dev/ptmx|${NONEXISTENT}|' ${WRKSRC}/configure

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
