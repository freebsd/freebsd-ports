# New ports collection Makefile for:	pictureboook
# Date created:			    	25 December 2000
# Whom:				    	Takanori Watanabe <takawata@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	picturebook
PORTVERSION=	20010422
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://samba.org/picturebook/
DISTNAME=	capture
EXTRACT_SUFX=  .tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SONY VAIO camera capture utility

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	imlib

.include <bsd.port.pre.mk>

post-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -o setbrightness setbrightness.c; \
	${CC} ${CFLAGS} -o vaiobat vaiobat.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/capture ${PREFIX}/bin/capture
	${INSTALL_PROGRAM} ${WRKSRC}/setbrightness ${PREFIX}/sbin/setbrightness
	${INSTALL_PROGRAM} ${WRKSRC}/vaiobat ${PREFIX}/sbin/vaiobat
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/README
.if!defined(NOPORTDOCS)
	${INSTALL_MAN} ${PATCHDIR}/README.FreeBSD ${DOCSDIR}/README.FreeBSD
.endif
.include <bsd.port.post.mk>
