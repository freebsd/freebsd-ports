# New ports collection makefile for:	robodoc
# Date created:				15 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	robodoc
PORTVERSION=	3.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		robodoc.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/robodoc/C
	${INSTALL_DATA} ${WRKSRC}/Examples/C/* \
		${PREFIX}/share/examples/robodoc/C
	@${MKDIR} ${PREFIX}/share/examples/robodoc/CPP
	${INSTALL_DATA} ${WRKSRC}/Examples/CPP/* \
		${PREFIX}/share/examples/robodoc/CPP
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/robodoc
.for file in AUTHORS ChangeLog NEWS README Docs/main.css Docs/robodoc.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/robodoc
.endfor
.endif

.include <bsd.port.mk>
