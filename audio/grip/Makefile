# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	2.96
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} 
MASTER_SITE_SUBDIR=grip
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@geeksrus.net

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
ALL_TARGET=	gripnopar gcd
MAN1=		grip.1
MLINKS=		grip.1 gcd.1

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grip ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gcd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/grip.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/grip
.for file in CHANGES CREDITS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/grip
.endfor
.endif

.include <bsd.port.mk>
