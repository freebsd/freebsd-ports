# New ports collection makefile for:	devel/p5-File-MimeInfo
# Date created:				Aug 21 2004
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	File-MimeInfo
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/P/PA/PARDUS/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Determine file type

BUILD_DEPENDS=	${SITE_PERL}/File/BaseDir.pm:${PORTSDIR}/devel/p5-File-BaseDir\
		${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		mimetype.1
MAN3=		File::MimeInfo::Cookbook.3 \
		File::MimeInfo::Magic.3 \
		File::MimeInfo::Rox.3 \
		File::MimeInfo.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
IGNORE=	Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
