# New ports collection makefile for:    xsol
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xsol
PORTVERSION=	2.1.1
CATEGORIES=	games
# mastersite disappeared in November 2002
MASTER_SITES=	# ftp://ftp.simcb.ru/pub/unix/src/
DISTNAME=	${PORTNAME}-new

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire

USE_IMAKE=	yes
MAN6=		xsol.6
PLIST_FILES=	bin/xsol

post-patch:
	@${ECHO_CMD} "MANSUFFIX=6" >> ${WRKSRC}/Imakefile

.include <bsd.port.mk>
