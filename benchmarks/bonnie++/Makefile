# ex:ts=8
# New ports collection makefile for:	bonnie++
# Date created:			Mar 24, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonnie++
PORTVERSION=	1.93.03		# a=01, b=02, c=03, ..., z=26, etc...
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/
DISTNAME=	${PORTNAME}-1.93c
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=	bon_csv2html.1 bon_csv2txt.1 generate_randfile.1
MAN8=	bonnie++.8 getc_putc.8 zcav.8

pre-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme.html ${DOCSDIR}

.include <bsd.port.mk>
