# New ports collection makefile for:	joe-devel
# Date created:		25 Jul 2001
# Whom:			dwcjr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe-devel
PORTVERSION=	2.9.7p1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	joe-editor
DISTNAME=	joe-${PORTVERSION:S/p/-pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	petef@databits.net

MAN1=		joe.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ALL_TARGET=	joe

post-patch:
	@${PERL} -pi -e 's!CFLAGS = -O2!CFLAGS +=!' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's!fprintf.*long time.*!!' ${WRKSRC}/conf.c
	@${PERL} -pi -e 's!2.9.6-pre1!2.9.7-pre0!' ${WRKSRC}/main.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/joe
	${INSTALL_DATA} ${WRKSRC}/INFO ${WRKSRC}/README ${PREFIX}/share/doc/joe
	${INSTALL_DATA} ${WRKSRC}/LIST ${PREFIX}/share/doc/joe/CommandList
.endif
.for file in jmacsrc jpicorc jstarrc rjoerc joerc
.if !exists(${PREFIX}/etc/${file})
	@${CP} ${PREFIX}/etc/${file}.dist ${PREFIX}/etc/${file}
.endif
.endfor

.include <bsd.port.mk>
