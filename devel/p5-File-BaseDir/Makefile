# New ports collection makefile for:	devel/p5-File-BaseDir
# Date created:				Aug 21 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	File-BaseDir
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/P/PA/PARDUS/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Use the freedesktop basedir spec

PERL_CONFIGURE=	yes

MAN3=		File::BaseDir.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/500503-*
.endif
.include <bsd.port.post.mk>
