# New ports collection makefile for:    portcheckout
# Date created:         1 November 1998
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	portcheckout
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.de.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org

USE_PERL5=	yes
MAN1=		portcheckout.1
MANCOMPRESSED=	maybe

post-patch:
	perl -pi -e 's^\#\!/usr/local/bin/perl^#!${PERL5}^' ${WRKSRC}/portcheckout.pl

.include <bsd.port.mk>
