# ex:ts=8
# New ports collection makefile for:	mp3asm
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3asm
PORTVERSION=	0.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

WRKSRC=	${WRKDIR}/mp3asm-0.1

post-extract:
	@${RM} ${WRKSRC}/config.cache

post-patch:
	@${PERL} -pi -e "s,getprogname,_getprogname,g" ${WRKSRC}/src/mp3asm.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
