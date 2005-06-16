# New ports collection makefile for:	p5-File-Spec
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	PathTools
PORTVERSION=	3.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module for portably manipulating file specifications

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	DEFINE="-DHAS_GETCWD"

MAN3=		Cwd.3 File::Spec.3 File::Spec::Cygwin.3 File::Spec::Epoc.3 \
		File::Spec::Functions.3 File::Spec::Mac.3 File::Spec::OS2.3 \
		File::Spec::Unix.3 File::Spec::VMS.3 File::Spec::Win32.3

.include <bsd.port.mk>
