# New ports collection makefile for:	gleyes
# Date created:		2 December 1998
# Whom:			Malte Lance <malte.lance@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gleyes
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/X11/acontrib/gleyes/ \
		ftp://ftp.kddlabs.co.jp/.1/X11/acontrib/gleyes/ \
		ftp://ftp.cit.nepean.uws.edu.au/unix/X/graphics/
# initial distribution location was http://puma.inf.ufpr.br/~claudio/gleyes/
# which is unresponsive since about 21.12.1998

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GLUT version of Xeyes

USE_X_PREFIX=	yes
USE_MESA=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		gleyes.1
PLIST_FILES=	bin/gleyes

.include <bsd.port.mk>
