# New ports collection makefile for:	robodoc
# Date created:				15 Dec 1999
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	robodoc
PORTVERSION=	4.99.8
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~rfsber/Robo/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Code reference program similar to cxref that produces HTML

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		robodoc.1 robohdrs.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robodoc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Source/robohdrs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Docs/robodoc.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Docs/robohdrs.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README Docs/manual.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/Examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
