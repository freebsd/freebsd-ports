# New ports collection makefile for:    imake-6
# Date created:         18 Jun 2004
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	1.0.4
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Imake and other utilities from X.Org

RUN_DEPENDS=	gccmakedep:${PORTSDIR}/devel/gccmakedep \
		makedepend:${PORTSDIR}/devel/makedepend \
		${PREFIX}/lib/X11/config/xorg.cf:${PORTSDIR}/x11/xorg-cf-files

USE_PERL5=	yes

XORG_CAT=	util
USE_XORG=	xproto

.ifdef USE_IMAKE
.error You have `USE_IMAKE' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

MAN1=		ccmakedep.1 \
		cleanlinks.1 \
		imake.1 \
		makeg.1 \
		mergelib.1 \
		mkdirhier.1 \
		mkhtmlindex.1 \
		revpath.1 \
		xmkmf.1

post-patch:
	@${PERL} -pi -e 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/mkhtmlindex.pl

.include <bsd.port.mk>
